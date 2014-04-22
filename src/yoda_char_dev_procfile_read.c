#include "yoda_char_dev.h"

int yoda_char_dev_procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data)
{
	int bytes_sent = 0;
	static int message_sent_index = 0;
	const char *msg = "Do, or do not.  There is no try!\n";
	int msg_length = strlen(msg);
	printk(KERN_INFO "%s trying to print via procfile...\n", DEVICE_NAME);
	if (offset > 0 && offset <= (msg_length - 1))
	{
		// reset the message index counter to resend the message fully next time.
		message_sent_index = 0;
		return 0;
	}
	bytes_sent = snprintf(buffer, (msg_length - offset), msg + offset);
	message_sent_index += bytes_sent;
	return bytes_sent;
}
