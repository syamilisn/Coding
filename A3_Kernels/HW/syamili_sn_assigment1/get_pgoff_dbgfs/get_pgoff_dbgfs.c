#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/debugfs.h>
#include <linux/slab.h>
#include <linux/version.h>
#include <linux/uaccess.h>
#include <linux/sched/signal.h>


#define OURMODNAME      "get_pgoff_dbgfs"
#define DBGFS_FILE1	"get_pgoff"

#define MAXUPASS 256
#define MAXBYTES 128
static struct dentry *gparent;
static int cause_an_oops;

DEFINE_MUTEX(mtx);

struct drv_ctx {
	char oursecret[MAXBYTES];
};

static struct drv_ctx *gdrvctx;

static ssize_t dbgfs_show_pgoff(struct file *filp, char __user * ubuf,
				size_t count, loff_t * fpos)
{

	char locbuf[MAXUPASS];

	if (mutex_lock_interruptible(&mtx))
		return -ERESTARTSYS;

	pr_debug("In the 'show' method: PAGE_OFFSET=0x%px\n", (void *)PAGE_OFFSET);

	snprintf(locbuf, MAXUPASS - 1, "0x%px\n", (void *)PAGE_OFFSET);

	mutex_unlock(&mtx);
	return simple_read_from_buffer(ubuf, MAXUPASS, fpos, locbuf, strlen(locbuf));
}

static const struct file_operations dbgfs_drvctx_fops = {
	.read = dbgfs_show_pgoff,
};

static struct drv_ctx *alloc_init_drvctx(void)
{
	struct drv_ctx *drvctx = NULL;

	drvctx = kzalloc(sizeof(struct drv_ctx), GFP_KERNEL);
	if (!drvctx)
		return ERR_PTR(-ENOMEM);
	pr_info("allocated and init the driver  structure\n");
	return drvctx;
}

static int __init debugfs_pgoff_init(void)
{
	int stat = 0;
	struct dentry *file1;

	if (!IS_ENABLED(CONFIG_DEBUG_FS)) {
		pr_warn("debugfs unsupported! Aborting ...\n");
		return -EINVAL;
	}

	gparent = debugfs_create_dir(OURMODNAME, NULL);
	if (!gparent) {
		pr_info("debugfs_create_dir failed, aborting...\n");
		stat = PTR_ERR(gparent);
		goto output_1;
	}

	gdrvctx = alloc_init_drvctx();
	if (IS_ERR(gdrvctx)) {
		pr_info("drv ctx alloc failed, aborting...\n");
		stat = PTR_ERR(gdrvctx);
		goto output_2;
	}

	file1 =debugfs_create_file(DBGFS_FILE1, 0444, gparent, (void *)gdrvctx,&dbgfs_drvctx_fops);

	if (!file1) {
		pr_info("debugfs_create_file failed, aborting...\n");
		stat = PTR_ERR(file1);
		goto output_3;
	}
	pr_debug("debugfs file /sys/kernel/debug/%s/%s created\n", OURMODNAME, DBGFS_FILE1);

	return 0;

 output_3:
	kfree(gdrvctx);
 output_2:
	debugfs_remove_recursive(gparent);
 output_1:
	return stat;
}

static void __exit debugfs_pgoff_exit(void)
{
	kfree(gdrvctx);
	debugfs_remove_recursive(gparent);
	pr_info("Exiting the cruel world!\n");
}

module_init(debugfs_pgoff_init);
module_exit(debugfs_pgoff_exit);


MODULE_AUTHOR("Syamili Sake Nag");
MODULE_DESCRIPTION("Debugfs-PAGE_OFFSET");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("1.0");

