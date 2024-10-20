#define pr_fmt(fmt) KBUILD_MODNAME ":%s:%d " fmt, __func__, __LINE__

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>

static void mem_leak(void)
{
	char *buf = kmalloc(32, GFP_KERNEL);
	if (buf) {
		memset(buf, 0, 32);
		// memory leak
		buf = kmalloc(64, GFP_KERNEL);
	}
}

static int __init my_memleak_init(void)
{
	pr_info("memleak module init\n");
	mem_leak();
	return 0;
}

static void __exit my_memleak_exit(void)
{
	pr_info("goodbye\n");
}

module_init(my_memleak_init);
module_exit(my_memleak_exit);
