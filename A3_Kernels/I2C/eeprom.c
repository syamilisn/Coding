/*
* Author     : Syamili S N              Filename   : eeprom
* Date       : 08-05-2023    	        Description: eeprom
*/


#include "script/headerskern.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("eeprom");
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
