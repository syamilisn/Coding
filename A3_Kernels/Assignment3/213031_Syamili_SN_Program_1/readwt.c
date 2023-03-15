/*
* Date       : 15-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : m4_readwt
* Description: read write to user space
*/


#include "run/headers.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("read write to user space");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");


#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__

#define OURMODNAME   "miscdrv_rdwr"

static int ga, gb = 1;		/* ignore for now ... */

struct drv_ctx {
	struct device *dev;
	int tx, rx, err, myword;
	u32 config1, config2;
	u64 config3;
#define MAXBYTES    128		
	char oursecret[MAXBYTES];
};
static struct drv_ctx *ctx;
static int open_miscdrv_rdwr(struct inode *inode, struct file *filp)
{
	struct device *dev = ctx->dev;
	char *buf = kzalloc(PATH_MAX, GFP_KERNEL);

	if (unlikely(!buf))
		return -ENOMEM;

	PRINT_CTX();	// displays process (or atomic) context info
	ga++;
	gb--;
	dev_info(dev, " opening \"%s\" now; wrt open file: f_flags = 0x%x\n",
		file_path(filp, buf, PATH_MAX), filp->f_flags);
	kfree(buf);

	return nonseekable_open(inode, filp);
}
static ssize_t read_miscdrv_rdwr(struct file *filp, char __user *ubuf,
				 size_t count, loff_t *off)
{
	int ret = count, secret_len = strnlen(ctx->oursecret, MAXBYTES);
	struct device *dev = ctx->dev;
	char tasknm[TASK_COMM_LEN];

	PRINT_CTX();
	dev_info(dev, "%s wants to read (upto) %zu bytes\n", get_task_comm(tasknm, current), count);

	ret = -EINVAL;
	if (count < MAXBYTES) {
		dev_warn(dev, "request # of bytes (%zu) is < required size"
			" (%d), aborting read\n", count, MAXBYTES);
		goto out_notok;
	}
	if (secret_len <= 0) {
		dev_warn(dev, "whoops, something's wrong, the 'secret' isn't"
			" available..; aborting read\n");
		goto out_notok;
	}

	ret = -EFAULT;
	if (copy_to_user(ubuf, ctx->oursecret, secret_len)) {
		dev_warn(dev, "copy_to_user() failed\n");
		goto out_notok;
	}
	ret = secret_len;

	// Update stats
	ctx->tx += secret_len;	// our 'transmit' is wrt this driver
	dev_info(dev, " %d bytes read, returning... (stats: tx=%d, rx=%d)\n",
		secret_len, ctx->tx, ctx->rx);
 out_notok:
	return ret;
}
static ssize_t write_miscdrv_rdwr(struct file *filp, const char __user *ubuf,
				  size_t count, loff_t *off)
{
	int ret = count;
	void *kbuf = NULL;
	struct device *dev = ctx->dev;
	char tasknm[TASK_COMM_LEN];

	PRINT_CTX();
	if (unlikely(count > MAXBYTES)) {	/* paranoia */
		dev_warn(dev, "count %zu exceeds max # of bytes allowed, "
			"aborting write\n", count);
		goto out_nomem;
	}
	dev_info(dev, "%s wants to write %zu bytes\n", get_task_comm(tasknm, current), count);

	ret = -ENOMEM;
	kbuf = kvmalloc(count, GFP_KERNEL);
	if (unlikely(!kbuf))
		goto out_nomem;
	memset(kbuf, 0, count);
	ret = -EFAULT;
	if (copy_from_user(kbuf, ubuf, count)) {
		dev_warn(dev, "copy_from_user() failed\n");
		goto out_cfu;
	}
	strlcpy(ctx->oursecret, kbuf, (count > MAXBYTES ? MAXBYTES : count));
#if 0
	/* Might be useful to actually see a hex dump of the driver 'context' */
	print_hex_dump_bytes("ctx ", DUMP_PREFIX_OFFSET,
			     ctx, sizeof(struct drv_ctx));
#endif
	// Update stats
	ctx->rx += count;	// our 'receive' is wrt userspace

	ret = count;
	dev_info(dev, " %zu bytes written, returning... (stats: tx=%d, rx=%d)\n",
		count, ctx->tx, ctx->rx);
 out_cfu:
	kvfree(kbuf);
 out_nomem:
	return ret;
}
static int close_miscdrv_rdwr(struct inode *inode, struct file *filp)
{
	struct device *dev = ctx->dev;
	char *buf = kzalloc(PATH_MAX, GFP_KERNEL);

	if (unlikely(!buf))
		return -ENOMEM;

	PRINT_CTX();		// displays process (or intr) context info
	ga--;
	gb++;
	dev_info(dev, " filename: \"%s\"\n", file_path(filp, buf, PATH_MAX));
	kfree(buf);

	return 0;
}

/* The driver 'functionality' is encoded via the fops */
static const struct file_operations llkd_misc_fops = {
	.open = open_miscdrv_rdwr,
	.read = read_miscdrv_rdwr,
	.write = write_miscdrv_rdwr,
	.llseek = no_llseek,	// dummy, we don't support lseek(2)
	.release = close_miscdrv_rdwr,
};

static struct miscdevice llkd_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,	/* kernel dynamically assigns a free minor# */
	.name = "llkd_miscdrv_rdwr",	/* when misc_register() is invoked, the kernel
	.mode = 0666,		/* ... dev node perms set as specified here */
	.fops = &llkd_misc_fops,	/* connect to this driver's 'functionality' */
};

static int __init miscdrv_rdwr_init(void)
{
	int ret = 0;
	struct device *dev;

	ret = misc_register(&llkd_miscdev);
	if (ret) {
		pr_notice("%s: misc device registration failed, aborting\n", OURMODNAME);
		return ret;
	}
	/* Retrieve the device pointer for this device */
	dev = llkd_miscdev.this_device;

	pr_info("LLKD misc driver (major # 10) registered, minor# = %d,"
		" dev node is /dev/%s\n", llkd_miscdev.minor, llkd_miscdev.name);
	ctx = devm_kzalloc(dev, sizeof(struct drv_ctx), GFP_KERNEL);
	if (unlikely(!ctx))
		return -ENOMEM;

	ctx->dev = dev;
	/* Initialize the "secret" value :-) */
	strlcpy(ctx->oursecret, "initmsg", 8);
	dev_dbg(ctx->dev, "A sample print via the dev_dbg(): driver initialized\n");

	return 0;		/* success */
}

static void __exit miscdrv_rdwr_exit(void)
{
	misc_deregister(&llkd_miscdev);
	pr_info("LLKD misc (rdwr) driver deregistered, bye\n");
}

module_init(miscdrv_rdwr_init);
module_exit(miscdrv_rdwr_exit);
