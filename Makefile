obj-m := yoda_device.o

yoda_device-objs := yoda_char_dev_open.o yoda_char_dev_release.o yoda_char_dev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
