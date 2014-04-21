#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include "yoda_char_dev.h"

MODULE_LICENSE("Dual MIT/GPL");

#define DEVICE_NAME "yodachardev"

static int Major;
static struct file_operations fops = {
	.open = yoda_char_dev_open,
	.release = yoda_char_dev_release
};

int __init yoda_char_dev_entry(void)
{
	Major = register_chrdev(0, "yodachardev", &fops);
	if (Major < 0)
	{
		printk(KERN_ALERT "Error registering yoda_char_dev\n");
		return Major;
	}
	else
	{
		printk(KERN_INFO "Registered %s at major number %d.\n", DEVICE_NAME, Major);
		printk(KERN_INFO "Be sure to set up a device node via something like \"mknod /dev/%s c %d 0\"\n", DEVICE_NAME, Major);
		return 0;
	}
}

module_init(yoda_char_dev_entry);

void __exit yoda_char_dev_exit(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
	printk(KERN_INFO "yoda_char_dev shutting down.\n");
}

module_exit(yoda_char_dev_exit);

static int yoda_char_dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "yoda_char_dev_open\n");
	try_module_get(THIS_MODULE);
	return 0;
}

static int yoda_char_dev_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	printk(KERN_INFO "yoda_char_dev_release\n");
	return 0;
}
