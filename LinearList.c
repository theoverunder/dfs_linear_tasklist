#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/sched.h>

struct task_struct *task;

int simple_init(void)
{
   printk(KERN_INFO "Module Begin:\n");
  for_each_process(task)
  {
    printk(KERN_INFO "ID: %d // Name: %s // State: %ld Parent: %d\n", task->pid, task->comm, task->state, task->parent->pid);
  }

 
  return 0;
}

void simple_exit(void)
{
  printk(KERN_INFO "Module Removed.\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linear List");
MODULE_AUTHOR("SeanD");

