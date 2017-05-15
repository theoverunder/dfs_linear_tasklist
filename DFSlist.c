#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/sched.h>


void dfsRecursion(struct task_struct * task)
{
	struct task_struct * nextTask; 
	struct list_head * list;

	list_for_each(list, &task->children) 
	{
		nextTask = list_entry(list, struct task_struct, sibling);
	
		printk(KERN_INFO " ID: %d // Parent: %d // Name: %s // State: %d  \n",  nextTask->pid, nextTask->parent->pid, 
			nextTask->comm, nextTask->state); // show parent id to show traversal order
	 
		dfsRecursion(nextTask);
	}

}
int simple_init(void)
{
  printk(KERN_INFO "Module Started:\n");
  dfsRecursion(&init_task);
  return 0;
}

void simple_exit(void)
{
  printk(KERN_INFO "Module Removed\n");
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("DFS Task List");
MODULE_AUTHOR("SeanD");

