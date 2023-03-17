/*
* Author     : Syamili S N
* Date       : 17-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : m6_mydriver
* Description: creating my own driver from scratch
*/


#include "run/headersmini.h"
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/slab.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("creating my own driver from scratch");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static int func_open(struct inode *inode, struct file *filp)
{
	char *buf = kzalloc(PATH_MAX, GFP_KERNEL);

	if(unlikely(!buf))
		return -ENOMEM;
	PRINT_CTX();	//	<convi.....h>

	pr_info("[module] FILE OPENING......\n");
	pr_info("[module] File path: %s\n", file_path(filp, buf, PATH_MAX));
	pr_info("[module] File flag: %x (write open file)\n", filp->f_flags);
	kfree(buf);
	return nonseekable_open(inode, filp);
}

static int func_close(struct inode *inode, struct file *filp)
{
	char *buf = kzalloc(PATH_MAX, GFP_KERNEL);
	if(unlikely(!buf))
		return -ENOMEM;
	pr_info("[module] FILE CLOSING......\n");
	pr_info("[module] File path: %s\n", file_path(filp, buf, PATH_MAX));
	pr_info("[module] File flag: %x\n", filp->f_flags);
	kfree(buf);
	return 0;
}

static ssize_t func_read(struct file *filp, char __user *ubuf, size_t count, loff_t *off)
{
	pr_info("[read~module] Bytes read: %zd\n", count);	
	return count;
}

static ssize_t func_write(struct file *filp, const char __user *ubuf, size_t count, loff_t *off)

{
	pr_info("[write~module] Bytes written: %zd\n", count);	
	return count;
}

static const struct file_operations myfops = {
	.open = func_open,
	.read = func_read,
	.write = func_write,
	.release = func_close,
	.llseek = no_llseek,
};

static struct miscdevice mydevice = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "mydriver",
	.mode = 0666,
	.fops = &myfops,
};

static int __init func_init(void)
{
	int ret;
	struct device *dev = mydevice.this_device;	//device pointer
	ret = misc_register(&mydevice);
	if(ret != 0){
		pr_notice("[module] MISC DEVICE REGISTRATION FAILED, ABORTING...\n");
		return ret;
	}
	pr_info("[module] MISC DEVICE REGISTRATION SUCCESS...\n");
	pr_info("[module] major#: %d\n", 10);
	pr_info("[module] minor#: %d\n", mydevice.minor);
	pr_info("[module]   name: %s\n", mydevice.name);
	dev_info(dev, "[module] sample dev_info() - minor#: %d\n", mydevice.minor);
	pr_info("Module initialized...\n");
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	misc_deregister(&mydevice);
	pr_info("Module exiting...\n");
}

module_init(func_init);
module_exit(func_exit);
