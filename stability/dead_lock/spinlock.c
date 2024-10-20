#define pr_fmt(fmt) KBUILD_MODNAME ":%s:%d " fmt, __func__, __LINE__

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static DEFINE_SPINLOCK(hack_spinA);
static DEFINE_SPINLOCK(hack_spinB);
void hack_spinAB(void)
{
	pr_info("hack_lockdep: A->B\n");
	spin_lock(&hack_spinA);
	spin_lock(&hack_spinB);
}

void hack_spinBA(void)
{
	pr_info("hack_lockdep: B->A\n");
	spin_lock(&hack_spinB);
}

static int __init lockdep_test_init(void)
{
	pr_info("my lockdep module init\n");
	hack_spinAB();
	hack_spinBA();
	return 0;
}

static void __exit lockdep_test_exit(void)
{
	pr_info("goodbye\n");
}
MODULE_LICENSE("GPL");
module_init(lockdep_test_init);
module_exit(lockdep_test_exit);
