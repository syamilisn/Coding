/*
* Author     : Syamili S N
* Date       : 23-06-2023
* Version    : #80~20.04.1-Ubuntu SMP Wed May 17 14:58:14 UTC 2023
* Release    : 5.15.0-73-generic
*
* Modulename : m1_debugfile
* Description: The kernel module created 2 files in debugfs:
	/sys/kernel/debug/example1
    /sys/kernel/debug/example1/hello
  Reading/writing to `hello` actually reads/writes to a variable in the module.

* Source     : https://github.com/versalinyaa/debugfs-tutorial/blob/master/example1/Makefile
*/


#include "run/headersmini.h"
#include <linux/debugfs.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("The kernel module created 2 files in debugfs");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

// This directory entry will point to `/sys/kernel/debug/example1`.
static struct dentry *dir = 0;

// File `/sys/kernel/debug/example1/hello` points to this variable.
static u32 hello = 0;

static int __init func_init(void)
{
	pr_info("Module initialized...\n");
    dir = debugfs_create_dir("example1", 0);
    if (!dir) {
        // Abort module load.
        printk(KERN_ALERT "debugfs_example1: failed to create /sys/kernel/debug/example1\n");
        return -1;
    }

    debugfs_create_u32("hello", 0666, dir, &hello);
    //there was code to check if above stat failed but removed it cuz of void error. (function doesn't return anything but we expected a value)
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
	debugfs_remove_recursive(dir);
}

module_init(func_init);
module_exit(func_exit);
