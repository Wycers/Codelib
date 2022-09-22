#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cred.h>

MODULE_LICENSE("Dual BSD/GPL");

static int km_init(void){
    printk("Hello Sunxiaokong's baby driver!\n");
    printk("Size of struct cred : %ld\n", sizeof(struct cred));
    printk("Size of type atomic_t : %ld\n", sizeof(atomic_t));
    printk("Size of type void* : %ld\n", sizeof(void*));
    printk("Size of type unsigned : %ld\n", sizeof(unsigned));
    printk("Size of type kuid_t : %ld\n", sizeof(kuid_t));
    return 0;
}

static void km_exit(void){
    printk("Goodbye, baby driver!\n");
}

module_init(km_init);
module_exit(km_exit);