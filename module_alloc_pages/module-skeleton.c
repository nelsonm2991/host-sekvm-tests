#include <linux/module.h>  /* Needed by all kernel modules */
#include <linux/kernel.h>  /* Needed for loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h>    /* Needed for __init and __exit macros. */
#include <linux/slab.h>    /* kmalloc */

// entry function
static int __init onload(void) {
    printk(KERN_EMERG "Loadable module initialized\n"); // print to /var/log/syslog

    printk(KERN_EMERG "Attempting as many alloc_page(1MB) calls as possible\n"); // print to /var/log/syslog

    struct page* result;
    u64 count;

    result = 0;
    count = 0;
    while (true) {
        result = alloc_pages(GFP_KERNEL, 8);
        if (result == NULL) {
            break;
        }
        count += 1;
    }

    // print count

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