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
