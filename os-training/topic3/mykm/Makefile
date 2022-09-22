obj-m := mykm.o
KERNEL_DIR := ../linux-5.18.9/
all:
	make -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.symvers *.mod.c *.mod.o *.order