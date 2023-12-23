#include <linux/module.h>  /* Needed by all kernel modules */
#include <linux/kernel.h>  /* Needed for loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h>    /* Needed for __init and __exit macros. */
#include <linux/slab.h>    /* kmalloc */

// entry function
static int __init onload(void) {
    printk(KERN_EMERG "Loadable module initialized\n"); // print to /var/log/syslog
    return 0;
}

// exit function
static void __exit onunload(void) {
    printk(KERN_EMERG "Loadable module removed\n");
}

// register entry/exit point functions
module_init(onload);
module_exit(onunload);

// module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mark Mester <mmester@parrylabs.com>");
MODULE_DESCRIPTION("A simple skeleton for a loadable Linux kernel module");