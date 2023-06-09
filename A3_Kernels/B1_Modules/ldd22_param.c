/*
* Author     : Syamili S N
* Date       : 09-06-2023
* Version    : #80~20.04.1-Ubuntu SMP Wed May 17 14:58:14 UTC 2023
* Release    : 5.15.0-73-generic
*
* Modulename : ldd22_param
* Description: module parameters
*/


#include "run/headersmini.h"
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("module parameters");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int __init func_init(void)
{
	pr_info("Module initialized...\n");
	pr_info("[param1~whom] : %s [param2~howmany]: %d \n", whom, howmany);
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
}

module_init(func_init);
module_exit(func_exit);
