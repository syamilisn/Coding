/*
* Author     : Syamili S N
* Date       : 09-06-2023
* Version    : #80~20.04.1-Ubuntu SMP Wed May 17 14:58:14 UTC 2023
* Release    : 5.15.0-73-generic
*
* Modulename : ldd2.1_currentproc
* Description: 
*/


#include "run/headersmini.h"
#include <asm/current.h>
#include <linux/sched.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");


static int __init func_init(void)
{
	pr_info("Module initialized...\n");
	pr_info("Current process [command~%s] : process id [id~%d]...\n", current->comm, current->pid);
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
	pr_info("Current process [command~%s] : process id [id~%d]...\n", current->comm, current->pid);
}

module_init(func_init);
module_exit(func_exit);
