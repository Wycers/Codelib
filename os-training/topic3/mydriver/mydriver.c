#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

static int major = 233;
static int minor = 233;

static dev_t devno;
static struct cdev cdev;

static int my_open(struct inode *inode, struct file *file)
{
    printk("my_open");
    return 0;
}

static struct file_operations my_ops =
{
    .open = my_open,
};

static int my_init(void)
{
    int ret;
    printk("my_init");
    devno = MKDEV(major, minor);
    ret = register_chrdev_region(devno, 1, "hello");
    if (ret < 0)
    {
        printk("register_chrdev_region failed\n");
        return ret;
    }

    cdev_init(&cdev, &my_ops);
    ret = cdev_add(&cdev, devno, 1);
    if (ret < 0)
    {
        printk("cdev_add failed\n");
        return ret;
    }
    return 0;
}

static void my_exit(void)
{
    printk("my_exit");
    cdev_del(&cdev);
    unregister_chrdev_region(devno, 1);
}

MODULE_LICENSE("GPL");
module_init(my_init);
module_exit(my_exit);