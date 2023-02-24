/*
* Date       : 23-02-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : m1_hello
* Description: prints hello world in kernel buffer
*/


#include "run/headers.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("prints hello world in kernel buffer");
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
