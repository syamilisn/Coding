/*
* Date       : 15-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : m3_mischardrv
* Description: 
* 	misc class: major #10
*/


#include "run/headers.h"

#define OURMODNAME "mischardrv"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

//	CODE BEGINS

static int open_miscdrv(struct inode *inode, struct file *filp)
{
        char *buf = kzalloc(PATH_MAX, GFP_KERNEL);

        if (unlikely(!buf))
                return -ENOMEM;
        PRINT_CTX();            // displays process (or atomic) context info

        pr_info(" opening \"%s\" now; wrt open file: f_flags = 0x%x\n",
                file_path(filp, buf, PATH_MAX), filp->f_flags);

        kfree(buf);
        return nonseekable_open(inode, filp);
}

static ssize_t read_miscdrv(struct file *filp, char __user *ubuf, size_t count, loff_t *off)
{
        pr_info("to read %zd bytes\n", count);
        return count;
}

static ssize_t write_miscdrv(struct file *filp, const char __user *ubuf,
                             size_t count, loff_t *off)
{
        pr_info("to write %zd bytes\n", count);
        return count;
}

static int close_miscdrv(struct inode *inode, struct file *filp)
{
        char *buf = kzalloc(PATH_MAX, GFP_KERNEL);

        if (unlikely(!buf))
                return -ENOMEM;
        pr_info("closing \"%s\"\n", file_path(filp, buf, PATH_MAX));
        kfree(buf);

        return 0;
}

static const struct file_operations llkd_misc_fops = {
        .open = open_miscdrv,
        .read = read_miscdrv,
        .write = write_miscdrv,
        .release = close_miscdrv,
        .llseek = no_llseek,
};

static struct miscdevice llkd_miscdev = {
        .minor = MISC_DYNAMIC_MINOR,    
        .name = "mischardrv",
        .mode = 0666,     
        .fops = &llkd_misc_fops,       
};

//	CODE ENDS

static int __init func_init(void)
{
	int ret;
        struct device *dev;

        ret = misc_register(&llkd_miscdev);
        if (ret != 0) {
                pr_notice("misc device registration failed, aborting\n");
                return ret;
        }

        /* Retrieve the device pointer for this device */
        dev = llkd_miscdev.this_device;
        pr_info("misc char driver (major # 10) registered, minor# = %d,"
                " dev node is /dev/%s\n", llkd_miscdev.minor, llkd_miscdev.name);

        dev_info(dev, "sample dev_info(): minor# = %d\n", llkd_miscdev.minor);


	printk(KERN_INFO "Initializing m3_mischardrv...\n");
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	misc_deregister(&llkd_miscdev);
	printk(KERN_INFO "Deregistering m3_mischardrv...\n");
}

module_init(func_init);
module_exit(func_exit);
