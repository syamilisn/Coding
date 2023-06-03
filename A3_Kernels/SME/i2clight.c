#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define DEVICE_NAME "lm393_light_sensor"
#define I2C_ADDR 0x48

static dev_t dev;
static struct cdev c_dev;
static struct class *cl;

static int lm393_light_sensor_open(struct inode *i, struct file *f)
{
    printk(KERN_INFO "lm393_light_sensor : open()\n");
    return 0;
}

static int lm393_light_sensor_close(struct inode *i, struct file *f)
{
    printk(KERN_INFO "lm393_light_sensor : close()\n");
    return 0;
}

static ssize_t lm393_light_sensor_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
    int ret;
    char data[2];
    struct i2c_msg msgs[2];
    struct i2c_rdwr_ioctl_data msgset = {
        .msgs = msgs,
        .nmsgs = 2,
    };

    msgs[0].addr = I2C_ADDR;
    msgs[0].flags = 0;
    msgs[0].len = 1;
    msgs[0].buf = data;

    msgs[1].addr = I2C_ADDR;
    msgs[1].flags = I2C_M_RD;
    msgs[1].len = 1;
    msgs[1].buf = data;

    ret = i2c_transfer(file->private_data, &msgset);
    if (ret < 0) {
        printk(KERN_ERR "lm393_light_sensor : i2c_transfer() failed\n");
        return ret;
    }

    printk(KERN_INFO "lm393_light_sensor : read() = %d\n", data[0]);
    return copy_to_user(buf, data, 1) ? -EFAULT : 1;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = lm393_light_sensor_open,
    .release = lm393_light_sensor_close,
    .read = lm393_light_sensor_read,
};

static int __init lm393_light_sensor_init(void)
{
    int ret;

    if ((ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME)) < 0) {
        printk(KERN_ERR "lm393_light_sensor : alloc_chrdev_region() failed\n");
        return ret;
    }

    cdev_init(&c_dev, &fops);
    if ((ret = cdev_add(&c_dev, dev, 1)) < 0) {
        printk(KERN_ERR "lm393_light_sensor : cdev_add() failed\n");
        unregister_chrdev_region(dev, 1);
        return ret;
    }

    if (IS_ERR(cl = class_create(THIS_MODULE, DEVICE_NAME))) {
        printk(KERN_ERR "lm393_light_sensor : class_create() failed\n");
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(cl);
    }

    if (IS_ERR(device_create(cl, NULL, dev, NULL, DEVICE_NAME))) {
        printk(KERN_ERR "lm393_light_sensor : device_create() failed\n");
        class_destroy(cl);
        cdev_del(&c_dev);
        unregister_chrdev_region(dev, 1);
        return PTR_ERR(device);
    }

    printk(KERN_INFO "lm393_light_sensor : module loaded\n");
    return 0;
}

static void __exit lm393_light_sensor_exit(void)
{
    device_destroy(cl, dev);
    class_destroy(cl);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "lm393_light_sensor : module unloaded\n");
}

module_init(lm393_light_sensor_init);
module_exit(lm393_light_sensor_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("LM393 Light Sensor Driver");
MODULE_LICENSE("GPL");