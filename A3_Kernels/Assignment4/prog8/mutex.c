/*
* Author     : Syamili S N
* Date       : 16-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : mutex
* Description: mutex lock
*/


#include "run/headers.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("mutex lock");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

#define BUF_LEN     256

static char my_buffer[BUF_LEN];
static int buf_pos = 0;
struct mutex my_mutex;
unsigned long chr_dev_global_variable = 0;
 
dev_t dev = 0;
static struct class *dev_class;
static struct cdev chr_dev_cdev;
 
 



/*
** This function will be called when we open the Device file
*/ 
static int chr_dev_open(struct inode *inode, struct file *file)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/
static int chr_dev_release(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/ 
static ssize_t chr_dev_read(struct file *filp, 
                char __user *buf, size_t len, loff_t *off)
{
        

        int remaining1;
        ssize_t retval;
        pr_info("Read function\n");
        mutex_lock(&my_mutex);

        remaining1 = buf_pos;
        if (remaining1 > len)
        {
            remaining1 = len;
        }

        if (copy_to_user(buf, my_buffer, remaining1))
        {
            retval = -EFAULT;
            goto done;
        }

        buf_pos -= remaining1;
        memmove(my_buffer, my_buffer + remaining1, buf_pos);

        retval = remaining1;

    done:
        mutex_unlock(&my_mutex);
        return retval;
 
        return 0;
}

/*
** This function will be called when we write the Device file
*/
static ssize_t chr_dev_write(struct file *filp, 
                const char __user *buf, size_t len, loff_t *off)
{
        

        int remaining2;
        ssize_t retval;
        pr_info("Write Function\n");
        mutex_lock(&my_mutex);

        remaining2 = BUF_LEN - buf_pos;
        if (remaining2 < len)
        {
            len = remaining2;
        }

        if (copy_from_user(my_buffer + buf_pos, buf, len))
        {
            retval = -EFAULT;
            goto done;
        }

        buf_pos += len;
        retval = len;

    done:
        mutex_unlock(&my_mutex);
        return retval;
        
}


//File operation structure
static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = chr_dev_read,
        .write          = chr_dev_write,
        .open           = chr_dev_open,
        .release        = chr_dev_release,
};
/*
** Module Init function
*/
static int __init chr_dev_driver_init(void)
{
        /*Allocating Major number*/
        if((alloc_chrdev_region(&dev, 0, 1, "chr_dev_Dev")) <0){
                pr_info("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        /*Creating cdev structure*/
        cdev_init(&chr_dev_cdev,&fops);
 
        /*Adding character device to the system*/
        if((cdev_add(&chr_dev_cdev,dev,1)) < 0){
            pr_info("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /*Creating struct class*/
        if(IS_ERR(dev_class = class_create(THIS_MODULE,"chr_dev_class"))){
            pr_info("Cannot create the struct class\n");
            goto r_class;
        }
 
        /*Creating device*/
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"chr_dev_device"))){
            pr_info("Cannot create the Device \n");
            goto r_device;
        }
 
        mutex_init(&my_mutex);
        
       
        
        pr_info("Device Driver Insert...Done!!!\n");
        return 0;
 
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        cdev_del(&chr_dev_cdev);
        return -1;
}

/*
** Module exit function
*/ 
static void __exit chr_dev_driver_exit(void)
{
        
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&chr_dev_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!\n");
}
 
module_init(chr_dev_driver_init);
module_exit(chr_dev_driver_exit);
