#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>


static short int shortint=1;
static int nint=999;
static long int longint=132141;
static char *string="hello kernel";
static int intarray[2]={1,1};


module_param(shortint,short,0);
MODULE_PARM_DESC(shortint,"A Short integer");
module_param(nint,int,0);
MODULE_PARM_DESC(nint,"Normal Integer");
module_param(longint,long,0);
MODULE_PARM_DESC(longint,"A Long integer");
module_param(string,charp,0);
MODULE_PARM_DESC(string,"A string");


static int __init params_init(void)
{
	printk(KERN_INFO "Short integer:%hd\n",shortint);
	printk(KERN_INFO "Normal Integer:%d",nint);
	printk(KERN_INFO "Long integer:%ld",longint);
	printk(KERN_INFO "String:%s",string);

	int i;

	for(i=0;i<(sizeof(intarray)/sizeof(int));i++)
	{
		printk(KERN_INFO "Element in Array:%d",intarray[i]);
	}	

	return 0;
}

static void __exit params_exit(void)
{
	printk(KERN_INFO "Exiting and cleaning up the Params module\n");
}

module_init(params_init);
module_exit(params_exit);
