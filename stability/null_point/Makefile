BASEINCLUDE ?= /lib/modules/$(shell uname -r)/build
KERNEL_DIR ?= /home/rlk/rlk/runninglinuxkernel_5.0

KBUILD_CFLAGS +=-g

np_access_zero_addr-objs := access_zero_addr.o 

obj-m	:=   np_access_zero_addr.o

all:
	$(MAKE) -C $(BASEINCLUDE) M=`pwd` modules;

.PHONY: clean
clean:
	$(MAKE) -C $(BASEINCLUDE) M=`pwd` clean;
	rm -f *.ko;

.PHONY: cc
cc:
	$(MAKE) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -C $(KERNEL_DIR) M=`pwd` modules;

.PHONY: cc_clean
cc_clean:
	$(MAKE) ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -C $(KERNEL_DIR) M=`pwd` clean;
	rm -f *.ko;

.PHONY: cp
cp:
	cp *.ko $(KERNEL_DIR)/kmodules/test -f
