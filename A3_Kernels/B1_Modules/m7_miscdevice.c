/*
* Author     : Syamili S N
* Date       : 06-07-2023
* Version    : #80~20.04.1-Ubuntu SMP Wed May 17 14:58:14 UTC 2023
* Release    : 5.15.0-73-generic
*
* Modulename : m7_miscdevice
* Description: simple misc device driver inspired by Youtube
*/


#include "run/headersmini.h"
#include <linux/fs.h>
#include <linux/miscdevice.h>

MODULE_AUTHOR("Syamili S N");
MODULE_DESCRIPTION("simple misc device driver inspired by Youtube");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");

/*
	step 4: implement callback functions
		step 4.1: int my_open(&inode, &file)
		step 4.2: int my_close(&inode, &file)
			->define MAX_SIZE
			->declare data[MAX_SIZE] and data_len
		step 4.3: my_write(&file, const user_buffer, user_len, loffset)
		step 4.4: my_read(&file, user_buffer, user_len, loffset)	// no const for user buffer since we are reading
*/

#define MAX_SIZE 256
static char data[MAX_SIZE];
static size_t data_len;

static int my_open(struct inode *inode, struct file *file){
	pr_info("misc_test - open called\n");
	//	inode variable: get information about the device file we are opening (major# and minor#)
	pr_info("major %d minor %d\n", imajor(inode), iminor(inode));			
	//	file variable: get info about file permissions (check if device was opened with read/write permissions)
	if(file->f_mode & FMODE_READ)
		pr_info("misc_test - open called with read permissions\n");
	if(file->f_mode & FMODE_WRITE)
		pr_info("misc_test - open called with write permissions\n");
	return 0;
}

static int my_close(struct inode *inode, struct file *file){	
	pr_info("misc_test - close called\n");
	return 0;
}
/*
	step 3: create file operations structure
*/

static ssize_t my_write(struct file *file, const char __user *user_buffer, size_t user_len, loff_t *ppos){
	//	params similar to write() system call. loffset is optional I think, unless lseek is used
	int status;
	if(user_len > data_len)
		data_len = MAX_SIZE;
	else
		data_len = user_len;
	pr_info("misc_test - write called\n");
	status = copy_from_user(data, user_buffer, data_len);
	if(status){
		pr_info("misc_device - error during copy_from_user");
		return -status;
	}
	return data_len;
}

static ssize_t my_read(struct file *file, char __user *user_buffer, size_t user_len, loff_t *ppos){
	//	user_buffer is not const	
	int status;
	size_t len;
	if(len < data_len)
		len = user_len;
	else
		len = data_len;
	pr_info("misc_test - read called\n");
	status = copy_to_user(user_buffer, data, len);
	if(status){
		pr_info("misc_device - error during copy_to_user");
		return -status;
	}
	return len;
}

static const struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_close,
};

/*
	step 1: create misc driver structure
*/
static struct miscdevice my_device = {
	.name = "testdev",	 		//	also the name that shows up in /dev
	.minor = MISC_DYNAMIC_MINOR,		//	auto choose minor#
	.fops = &fops,
};

/*
	step 2: register(__init) and deregister(__exit) misc driver structure
*/
static int __init func_init(void)
{
	int status;
	pr_info("Module initialized...\n");
	pr_info("misc_test - register misc device\n");
	status = misc_register(&my_device);
	if(status){
		pr_info("misc device registration error");
		return -status;
	}
	return 0;		/* success */
}

static void __exit func_exit(void)
{
	pr_info("Module exiting...\n");
	pr_info("misc_test - deregister misc device\n");
	misc_deregister(&my_device);
}

module_init(func_init);
module_exit(func_exit);
