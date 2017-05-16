#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>	
#include <linux/uaccess.h>

static int major;
static int device_usage=0;

static char msg[80];
static char* msg_ptr;


int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *inode, struct file *file);
static int device_release(struct inode *inode,struct file *file);
static ssize_t device_read(struct file *filep,char *buffer,size_t length,loff_t *offset);
static ssize_t device_write(struct file *filep,char *buffer, size_t length, loff_t *offset);


static struct file_operation fops={
	.read=device_read;
	.write=device_writel
	.open=device_open;
	.release=device_release;
};

int init_module(void)
{
	major=register_chrdev(0,"chardev",&fops);
	
	if(major<0)
	{
		printk(KERN_ALERT "Error in getting major number for device!!\n");
		return major;
	}
	
	printk(KERN_INFO "Registration of device was success with Major number as:%d",major);
	return 0;	
}

void cleanup_module(void)
{
	int unreg;
	unreg=unregister_chrdev(major,"chrdev");
	if(unreg<0)
	{
		printk(KERN_ALERT "Error in unregistering the device!!\n");
	}
}


static int device_open(struct inode *inode, struct file *file)
{
	static int counter=0;
	
	if(Device_Open)
	{
		return -EBUSY;
	}

	device_usage++;
	counter++;
	sprintf(msg,"You have already opened this file %d times.",counter)
	msg_ptr=msg;
	try_module_get(THIS_MODULE);

	return 0;	
}

static int device_release(struct inode *inode,struct file *file)
{
	device_usage--;
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t device_read(struct file *filep,char *buffer,size_t length,loff_t *offset)
{
	int bytes_read=0;
	if(*msg_ptr==0)
	{
		return 0;
	}

	while(length && *msg_ptr)
	{
		put_user(*(msg_ptr),buffer++);
		length--;
		bytes_read++;
	}

	return bytes_read;
}

static ssize_t device_write(struct file *filep,char *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "This operation is not valid!!\n");
	return -EINVAl;
}
