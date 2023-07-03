/*
* Date       : 16-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : m5_passargs
* Description: passing arguments to driver
* 	# insmod m5_passargs.ko value=100 name="shyam" arr_value=1,2,3,4
* 	........check dmesg
* 	.
* 	.
* 	# echo 123 > /sys/module/m5_passargs/parameters/cb_value
* 	........check dmesg
*/


#include "run/headers.h"
#include <linux/moduleparam.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("passing arguments to driver");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

int value, arr_value[4];
char *name;
int cb_value = 0;

module_param(value, int, S_IRUSR| S_IWUSR);
module_param(name, charp, S_IRUSR|S_IWUSR);
module_param_array(arr_value, int, NULL, S_IRUSR|S_IWUSR);

int notify_param(const char *val, const struct kernel_param *kp)	//when cb_value is modified manually, message is displayed in dmesg
{
	int res = param_set_int(val, kp);
	if(res == 0){
		printk(KERN_INFO "[notify_param] Call back function called...\n");
		printk(KERN_INFO "[notify_param] cb_value = %d\n", cb_value);
		return 0;
	}
	return -1;
}

const struct kernel_param_ops my_param_ops = 
{
	.set = &notify_param,
	.get = &param_get_int,
};

module_param_cb(cb_value, &my_param_ops, &cb_value, S_IRUGO| S_IWUSR);

static int __init func_init(void)
{
	int i;
	printk(KERN_INFO "*** passargs initalized***\n");
	printk(KERN_INFO "[mod~passargs] value = %d\n", value);
	printk(KERN_INFO "[mod~passargs] cb_value = %d\n", cb_value);
	printk(KERN_INFO "[mod~passargs] name = %s\n", name);
	for(i=0; i< (sizeof arr_value / sizeof (int)); i++)
	{
		printk(KERN_INFO "[mod:passargs] arr_value%d = %d\n", i, arr_value[i]);
	}
	printk(KERN_INFO "[mod:passargs] Module inserted successfully...!\n");
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	printk(KERN_INFO "[mod:passargs] Module removed successfully...!\n");
}

module_init(func_init);
module_exit(func_exit);
