#include <linux/init.h>
#include <linux/fs.h>
#include <linux/module.h>
#include "yoda_char_dev.h"

static int yoda_char_dev_open(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE);
	printk(KERN_INFO "%s opened\n");
	return 0;
}
