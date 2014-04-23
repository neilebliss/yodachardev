#include "yoda_char_dev.h"

MODULE_LICENSE("Dual MIT/GPL");

#define DEVICE_NAME "yodachardev"

static int Major;
static struct file_operations fops = {
	.open = yoda_char_dev_open,
	.release = yoda_char_dev_release,
	.unlocked_ioctl = yoda_char_dev_ioctl
};

struct proc_dir_entry *proc_file;
static bool msg_a = true;

int __init yoda_char_dev_entry(void)
{
	Major = register_chrdev(0, "yodachardev", &fops);
	if (Major < 0)
	{
		printk(KERN_ALERT "Error setting up character device %s: %d", DEVICE_NAME, Major);
		return Major;
	}
	
	proc_file = create_proc_entry(DEVICE_NAME, 0644, NULL);
	if (proc_file == NULL)
	{
		remove_proc_entry(DEVICE_NAME, NULL);
		unregister_chrdev(Major, DEVICE_NAME);
		return -ENOMEM;
	}
	proc_file->read_proc = yoda_char_dev_procfile_read;
	proc_file->mode = S_IFREG | S_IRUGO;
	proc_file->uid = 0;
	proc_file->gid = 0;
	proc_file->size = 37;

	printk(KERN_INFO "Registered %s at major number %d.\n", DEVICE_NAME, Major);
	printk(KERN_INFO "Be sure to set up a device node via something like \"mknod /dev/%s c %d 0\"\n", DEVICE_NAME, Major);
	return 0;
}

module_init(yoda_char_dev_entry);

void __exit yoda_char_dev_exit(void)
{
	remove_proc_entry(DEVICE_NAME, NULL);
	unregister_chrdev(Major, DEVICE_NAME);
	printk(KERN_INFO "yoda_char_dev shutting down.\n");
}

module_exit(yoda_char_dev_exit);

char* get_output_message(void)
{
	if (msg_a)
	{
		return "Looking for someone?\n";
	}
	else
	{
		return "Found someone you have!\n";
	}
}

void switch_output_message(void)
{
	msg_a = !msg_a;
}
