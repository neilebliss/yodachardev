#include "yoda_char_dev.h"

int yoda_char_dev_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	printk(KERN_INFO "%s shutting down\n", DEVICE_NAME);
	return 0;
}

