obj-m += main.o


# my_module-objs := ssd1306.o
# my_module-y := main.o

KDIR = /lib/modules/$(shell uname -r)/build



all: module dt
	echo Builded device tree overlat and kernel module
module:
	make -C $(KDIR)  M=$(shell pwd) modules
dt: oleddts.dts
	dtc -@ -I dts -O dtb -o oleddts.dtbo oleddts.dts
clean:
	make -C $(KDIR)  M=$(shell pwd) clean
	rm -rf oleddts.dtbo
