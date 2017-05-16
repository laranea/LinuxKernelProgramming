#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void)
{
	printk(KERN_INFO "Module Initialized\n" );
	return 0; //Zero mean no error. Anything other than that will give an error
} 

void cleanup_module(void)
{
	printk(KERN_INFO "Module Exited\n");
}
