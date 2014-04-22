#include "yoda_char_dev.h"

int yoda_char_dev_procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data)
{
	int ret = 0;
	char *msg = "Do, or do not.  There is no try!";
	printk(KERN_INFO "%s trying to print via procfile...\n", DEVICE_NAME);
	if (offset > 0)
	{
		return 0;
	}
	ret = sprintf(buffer, msg);
	return ret;
}
