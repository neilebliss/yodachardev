#include "yoda_char_dev.h"

int yoda_char_dev_procfile_write(struct file *file, const char __user *buffer, unsigned long count, void *data)
{
	switch_output_message();
	return count;
}

