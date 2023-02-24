/*
* Date       : 24-02-2023
* Version    : #33~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Mon Jan 30 17:03:34 UTC 2
* Release    : 5.19.0-32-generic
*
* Modulename : dum
* Description: dum
*/


#include "run/headers.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("dum");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");


static int __init func_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	printk(KERN_INFO "Goodbye, world\n");
}

module_init(func_init);
module_exit(func_exit);
