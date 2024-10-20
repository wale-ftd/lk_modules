#define pr_fmt(fmt) KBUILD_MODNAME ":%s:%d " fmt, __func__, __LINE__

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static void create_oops(void)
{
	*(int *)0 = 0;
}

static int __init my_oops_init(void)
{
	pr_info("oops module init\n");
	create_oops();
	return 0;
}

static void __exit my_oops_exit(void)
{
	pr_info("goodbye\n");
}

module_init(my_oops_init);
module_exit(my_oops_exit);
