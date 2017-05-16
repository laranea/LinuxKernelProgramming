#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int variable __initdata=3;

static int __init module_3_init(void)
{
	printk(KERN_INFO "Module %d has been initialized\n",variable);
	return 0;
}


static void __exit module_3_exit(void)
{
	printk(KERN_INFO "Module %d has benn exited\n",variable);
}

module_init(module_3_init);
module_exit(module_3_exit);
