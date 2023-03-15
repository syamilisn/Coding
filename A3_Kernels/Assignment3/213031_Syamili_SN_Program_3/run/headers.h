#include <linux/init.h>		//init
#include <linux/kernel.h>	//printk
#include <linux/module.h>	//module desc.

//	convenience files
#include "convenient.h"	//convenient macros and routines

//	misc device driver
#include <linux/miscdevice.h>		//misc device
#include <linux/fs.h>		//file data structures, fops
#include <linux/slab.h>		//k[m|z]alloc(), k[z]free()
	//list of flags set at cache creation which affect how the slab is structured
	
//	misc device driver user to kernal data transfer - copy_[to|from]_user()
#include <linux/mm.h>		//kvmalloc()
#include <linux/sched.h>	//get_task_comm()

#include <linux/version.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(4, 11, 0)
#include <linux/uaccess.h>
#else
#include <asm/uaccess.h>
#endif

//	others
#include <linux/kdev_t.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>

#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__
#include <linux/ioctl.h>
#include<linux/kobject.h> 

