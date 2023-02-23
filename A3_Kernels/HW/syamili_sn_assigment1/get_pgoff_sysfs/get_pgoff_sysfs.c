#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/mutex.h>
#include <linux/slab.h>

#define NAME "get_pgoff_sysfs"

//sysfile :
#define SYSFS_FILE1 get_pgoff


static DEFINE_MUTEX(mtx);

static ssize_t get_pgoff_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	int n;

	if (mutex_lock_interruptible(&mtx))
		return -ERESTARTSYS;
	pr_debug("In the 'show' method: PAGE_OFFSET=0x%px\n", (void *)PAGE_OFFSET);
	n = snprintf(buf, 25, "0x%px", (void *)PAGE_OFFSET);
	mutex_unlock(&mtx);
	return n;
}

static DEVICE_ATTR_RO(SYSFS_FILE1);

static struct miscdevice get_pgoff = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "get_pgoff_sysfs",
	.mode = 0666,
};

static int __init sysfs_page_init(void)
{
	int stat = 0;
	struct device *dev;

	stat = misc_register(&get_pgoff);
	pr_info("Misc driver registered\n");
	if (unlikely(!IS_ENABLED(CONFIG_SYSFS))) 
	{
		pr_warn("sysfs unsupported! Aborting ...\n");
		return -EINVAL;
	}
	if (stat != 0) 
	{
		pr_notice("device registration failed\n");
		goto o1;
	}
	dev = get_pgoff.this_device;
	stat = device_create_file(dev, &dev_attr_SYSFS_FILE1);
	if (stat) 
	{
		pr_info("device_create_file [2] failed (%d), aborting now\n", stat);
		goto o2;
	}
	return 0;
o2:
		misc_deregister(&get_pgoff);
o1:
		return stat;
}

static void __exit sysfs_page_exit(void)
{
	misc_deregister(&get_pgoff);
	pr_info("Module Exited.\n");
}

module_init(sysfs_page_init);
module_exit(sysfs_page_exit);


MODULE_AUTHOR("Syamili Sake Nag");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("1.0");





