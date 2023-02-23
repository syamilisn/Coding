#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq_work.h>
#include <linux/preempt.h>

#define OURMODNAME "irqwork"


static struct irq_work irq_work_interrupt;
static struct irq_work irq_work_process;


static void my_irqwork(struct irq_work *func)
{
	
	
	if(in_task())
	{
		
		pr_info("%s : my_irqwork : running in process context\n",OURMODNAME);
	}
	else
	{
		pr_info("%s : my_irqwork : running in interrupt context\n",OURMODNAME);
	}
}



static int __init intr_drv_init(void)
{
	int i;

	
	
	init_irq_work(&irq_work_interrupt, my_irqwork);
	

	
	irq_work_queue(&irq_work_interrupt);
		
	
	

	return 0;		// success
}

static void __exit intr_drv_exit(void)
{
	pr_info("irqwork module exited\n");
}

module_init(intr_drv_init);
module_exit(intr_drv_exit);

MODULE_AUTHOR("Syamili Sake Nag");
MODULE_LICENSE("Dual MIT/GPL");
