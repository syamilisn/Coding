#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc4162456, "module_layout" },
	{ 0x57630285, "no_llseek" },
	{ 0x719bc1c4, "misc_deregister" },
	{ 0x1da88f1a, "_dev_info" },
	{ 0xdf5f86e7, "misc_register" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1afa97f, "nonseekable_open" },
	{ 0x37a0cba, "kfree" },
	{ 0x596c125d, "file_path" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x386a1fc1, "pv_ops" },
	{ 0xb0a9e012, "current_task" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xa926a2db, "kmem_cache_alloc_trace" },
	{ 0x57b41c5c, "kmalloc_caches" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x92997ed8, "_printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6E37B2F77E06E7F1CF836C6");
