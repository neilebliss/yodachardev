obj-m += yodachardev.o

yodachardev-objs := yoda_char_dev_ioctl.o yoda_char_dev_open.o yoda_char_dev_release.o yoda_char_dev_procfile_read.o yoda_char_dev.o

EXTRA_CFLAGS += -I$(PWD)/include -Wall -Werror

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
