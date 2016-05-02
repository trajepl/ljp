
/* make -C /lib/modules/4.5.1-1-ARCH/build M=/home/ljp/ljp/linux/mod */
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void) {
	printk("Hello World!\n");
	return 0;
}

static void hello_exit(void) {
	printk("Goodbye!");
}

module_init(hello_init);
module_exit(hello_exit);
