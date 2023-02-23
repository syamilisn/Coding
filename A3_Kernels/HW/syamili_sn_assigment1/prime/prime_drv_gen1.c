#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include<linux/slab.h>                 //kmalloc()
#include<linux/uaccess.h>              //copy_to/from_user()
#include <linux/ioctl.h>
#include <linux/err.h>
#include <linux/spinlock.h>

#define MAX_PRIME 500

struct prime_drv_data {
    int start;
    int end;
    int flags;
};

#define WR_VALUE _IOW('a','a',struct prime_drv_data*)
#define RD_VALUE _IOR('a','b',struct prime_drv_data*)
 
static int max_prime = MAX_PRIME;

module_param(max_prime, int, 0644);

static int i;

static int is_prime(int n) {
    if (n <= 1)
        return 0;
    for ( i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


static struct prime_drv_data prime_data;
static spinlock_t lock;

int32_t value = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

/*
** Function Prototypes
*/
static int      __init etx_driver_init(void);
static void     __exit etx_driver_exit(void);
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long     etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/*
** File operation sturcture
*/
static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = etx_read,
        .write          = etx_write,
        .open           = etx_open,
        .unlocked_ioctl = etx_ioctl,
        .release        = etx_release,
};

/*
** This function will be called when we open the Device file
*/
static int etx_open(struct inode *inode, struct file *file)
{
        pr_info("Device File open.\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/
static int etx_release(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed.\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        int prime;
        char buffer[10];
    	spin_lock(&lock);
    	
   	
   	
   	
    	while (!is_prime(prime_data.start))
        	prime_data.start++;
        prime = prime_data.start++;
        if (prime > prime_data.end) {
        	spin_unlock(&lock);
        	goto exit;
   	}
    	
    	spin_unlock(&lock);
    	
    	
    	sprintf(buffer, "%d", prime);
    	
    	if (copy_to_user(buf, &buffer, sizeof(prime)))
        	return -EFAULT;
        	
        pr_info("Data sent to user space = %d\n",prime);
    	return sizeof(prime);
exit:
	pr_info("Exit\n");
	return -1;
}

/*
** This function will be called when we write the Device file
*/
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Write function\n");
        return len;
}

/*
** This function will be called when we write IOCTL on the Device file
*/
static long etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct prime_drv_data data;
	
         switch(cmd) {
                case WR_VALUE:
                	pr_info("Data writing\n");
                        if( copy_from_user(&data, (char *)arg, sizeof(data)))
                        {
                                pr_err("Data Write : Err!\n");
                                return -EFAULT;
                        }
                        if (data.end > max_prime)
            			return -EINVAL;
            		spin_lock(&lock);
            		prime_data = data;
            		spin_unlock(&lock);
                        pr_info("start = %d\n", data.start);
                        pr_info("end = %d\n", data.end);
                        break;
                
                default:
                        pr_info("Default\n");
                        break;
        }
        return 0;
}
 
/*
** Module Init function
*/
static int __init etx_driver_init(void)
{
        /*Allocating Major number*/
        spin_lock_init(&lock);
        if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev")) <0){
                pr_err("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        /*Creating cdev structure*/
        cdev_init(&etx_cdev,&fops);
 
        /*Adding character device to the system*/
        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_err("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /*Creating struct class*/
        if(IS_ERR(dev_class = class_create(THIS_MODULE,"etx_class"))){
            pr_err("Cannot create the struct class\n");
            goto r_class;
        }
 
        /*Creating device*/
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"etx_device"))){
            pr_err("Cannot create the Device 1\n");
            goto r_device;
        }
        pr_info("Device Driver inserted.\n");
        return 0;
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}

/*
** Module exit function
*/
static void __exit etx_driver_exit(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&etx_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver exited.\n");
}
 
module_init(etx_driver_init);
module_exit(etx_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Syamili Sake Nag");
MODULE_VERSION("1.5");
