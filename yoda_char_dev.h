#ifndef YODA
#define YODA
int yoda_char_dev_entry(void);
void yoda_char_dev_exit(void);
static int yoda_char_dev_open(struct inode *, struct file *);
static int yoda_char_dev_release(struct inode *, struct file *);
#define DEVICE_NAME "yodachardev"
#endif
