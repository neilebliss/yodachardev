#include "yoda_char_dev.h"

extern bool procfile_message_a;

long yoda_char_dev_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	switch_output_message();
	return 0;
}

