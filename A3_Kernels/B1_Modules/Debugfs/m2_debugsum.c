/*
* Author     : Syamili S N
* Date       : 23-06-2023
* Version    : #80~20.04.1-Ubuntu SMP Wed May 17 14:58:14 UTC 2023
* Release    : 5.15.0-73-generic
*
* Modulename : m2_debugsum
* Description: add numbers and view sum in debugfs
*/


#include "run/headersmini.h"
#include <linux/debugfs.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("add numbers and view sum in debugfs");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

// This directory entry will point to `/sys/kernel/debug/example2`.
static struct dentry *dir = 0;

// File `/sys/kernel/debug/example2/sum` points to this variable.
static u32 sum = 0;

static int add_write_op(void *data, u64 value)
{
    sum += value;
	return 0;
}

DEFINE_SIMPLE_ATTRIBUTE(add_fops, NULL, add_write_op, "%llu\n");	// shortcut macro to define file operations

static int __init func_init(void)
{
	pr_info("Module initialized...\n");

	struct dentry *junk;
	dir = debugfs_create_dir("example2", 0);
    if (!dir) {
        // Abort module load.
        printk(KERN_ALERT "debugfs_example2: failed to create /sys/kernel/debug/example2\n");
        return -1;
    }
	junk = debugfs_create_file(
            "add",
            0222,
            dir,
            NULL,
            &add_fops);
    if (!junk) {
        // Abort module load.
        printk(KERN_ALERT "debugfs_example2: failed to create /sys/kernel/debug/example2/add\n");
        return -1;
    }
	debugfs_create_u32("sum", 0444, dir, &sum);

	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
	debugfs_remove_recursive(dir);
}

module_init(func_init);
module_exit(func_exit);
