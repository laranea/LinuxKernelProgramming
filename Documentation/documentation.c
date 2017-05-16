#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>


#define AUTHOR "A temporary Author Name"
#define DESCRIPTION "A very basic kernel module to showcase documentation"

static int __init documentation_module_init(void)
{
	printk(KERN_INFO "Initialized the documentation module\n");
	return 0;
}

static void __exit documentation_module_exit(void)
{
	printk(KERN_INFO "Exiting the documentation module\n");
}

module_init(documentation_module_init);
module_exit(documentation_module_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_AUTHOR(AUTHOR);
MODULE_SUPPORTED_DEVICE("test device");
