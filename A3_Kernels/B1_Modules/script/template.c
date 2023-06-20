static int __init func_init(void)
{
	pr_info("Module initialized...\n");
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
}

module_init(func_init);
module_exit(func_exit);
