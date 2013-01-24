#ifndef __KERNEL__
#define __KERNEL__
#endif

#ifndef MODULE
#define MODULE
#endif
/* 
 * hello.c - The Hello, World Kernel Module
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* 
 * hello_init - the init function, called when the module is loaded.
 * Return zero if successfully loaded, nonzero otherwise.
 */
static int
hello_init(void)
{
        printk(KERN_ALERT "I bear a charmed life.\n");
        return 0;
}

/*
 * hello_exit - the exit function, called when module is removed
 */
static hello_exit(void)
{
        printk(KERN_ALERT "Out, Out, brief candle!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Q");
MODULE_DESCRIPTION("A Hello, World Module");
