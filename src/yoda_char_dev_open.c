#include "yoda_char_dev.h"

int yoda_char_dev_open(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	printk(KERN_INFO "%s opened\n", DEVICE_NAME);
	return 0;
}
