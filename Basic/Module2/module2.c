#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init module_2_init(void)
{
	printk(KERN_INFO "Intialized Module 2\n");
	return 0;
}

static void __exit module_2_exit(void)
{
	printk(KERN_INFO "Exited Module 2\n");
}

module_init(module_2_init);
module_exit(module_2_exit);
