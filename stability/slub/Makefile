BASEINCLUDE ?= /lib/modules/$(shell uname -r)/build
KERNEL_DIR ?= /home/rlk/rlk/runninglinuxkernel_5.0

slub_oob_memset-objs := out_of_bounds_memset.o 
slub_oob_left-objs := out_of_bounds_left.o 
slub_df-objs := double_free.o 
slub_uaf-objs := use_after_free.o 

obj-m	:=   slub_oob_memset.o
obj-m	+=   slub_oob_left.o
obj-m	+=   slub_df.o
obj-m	+=   slub_uaf.o

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
