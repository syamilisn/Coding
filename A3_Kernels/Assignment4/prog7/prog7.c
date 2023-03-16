/*
* Author     : Syamili S N
* Date       : 16-03-2023
* Version    : #58~20.04.1-Ubuntu SMP Thu Oct 13 13:09:46 UTC 2022
* Release    : 5.15.0-52-generic
*
* Modulename : prog7
* Description: interrupts part 3
*/


#include "run/headers.h"

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("interrupts part 3");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");
#include <linux/interrupt.h>
#include <asm/io.h>
#include <asm/hw_irq.h>
#include <linux/err.h>

#define mem_size        1024           //Memory Size
#define IRQ_NO 11
 


/*
request_irq is a function in the Linux kernel used to request a particular interrupt line from the system
*/

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

void tasklet_fn(unsigned long); 
/* Tasklet by Dynamic Method */
struct tasklet_struct *tasklet = NULL;
 
 
/*Tasklet Function*/
void tasklet_fn(unsigned long arg)
{
        printk(KERN_INFO "Executing Tasklet Function : arg = %ld\n", arg);
}
 
 
//Interrupt handler for IRQ 11. 
static irqreturn_t irq_handler(int irq,void *dev_id) {
        printk(KERN_INFO "Shared IRQ: Interrupt Occurred");
        /*Scheduling Task to Tasklet*/
        tasklet_schedule(tasklet); 
        
        return IRQ_HANDLED;
}
 
/*
** This function will be called when we read the Device file
*/
static ssize_t data_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        
        asm("int $0x3B");  // Corresponding to irq 11
        return 0;
}





static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = data_read,
     
       
};
/*
** Module Init function
*/
static int __init char_driver_init(void)
{
        /*Allocating Major number*/
        if((alloc_chrdev_region(&dev, 0, 1, "mychar_device")) <0){
                pr_info("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        /*Creating cdev structure*/
        cdev_init(&etx_cdev,&fops);
 
        /*Adding character device to the system*/
        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_info("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /*Creating struct class*/
        if(IS_ERR(dev_class = class_create(THIS_MODULE,"char_class"))){
            pr_info("Cannot create the struct class\n");
            goto r_class;
        }
 
        /*Creating device*/
        if(IS_ERR(device_create(dev_class,NULL,dev,NULL,"mychar_device"))){
            pr_info("Cannot create the Device 1\n");
            goto r_device;
        }
        
       

        if (request_irq(IRQ_NO, irq_handler, IRQF_SHARED, "mychar_device", (void *)(irq_handler))) {
            printk(KERN_INFO "etx_device: cannot register IRQ ");
            goto irq;
        }
        /* Init the tasklet bt Dynamic Method */
        tasklet  = kmalloc(sizeof(struct tasklet_struct),GFP_KERNEL);
        if(tasklet == NULL) {
            printk(KERN_INFO "etx_device: cannot allocate Memory");
            goto irq;
        }
        tasklet_init(tasklet,tasklet_fn,0);

        pr_info("Device Driver Insert...Done!!!\n");
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
static void __exit char_driver_exit(void)
{
  	 free_irq(IRQ_NO, &etx_cdev);
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&etx_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}
 
module_init(char_driver_init);
module_exit(char_driver_exit);
