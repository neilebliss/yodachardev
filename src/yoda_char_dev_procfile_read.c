#include "yoda_char_dev.h"

int yoda_char_dev_procfile_read(char *buffer, char **buffer_location, off_t offset, int buffer_length, int *eof, void *data)
{
	sprintf(buffer, "Do, or do not.  There is no try!");
	return 0;
}
