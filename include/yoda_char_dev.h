#ifndef YODA
#define YODA
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
int yoda_char_dev_entry(void);
void yoda_char_dev_exit(void);
int yoda_char_dev_open(struct inode *, struct file *);
int yoda_char_dev_release(struct inode *, struct file *);
int yoda_char_dev_procfile_read(char *, char **, off_t, int, int *, void *);
long yoda_char_dev_ioctl(struct file *, unsigned int, unsigned long);
char * get_output_message(void);
void switch_output_message(void);
#define DEVICE_NAME "yodachardev"
#endif
