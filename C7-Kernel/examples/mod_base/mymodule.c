#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("JB Besnard");
MODULE_DESCRIPTION("Keylogger");
MODULE_VERSION("0.1");


static int __init mymod_init(void){
	pr_info("Yo le module\n");
	return 0;
}


static void __exit mymod_exit(void){
	pr_info("FINI le module\n");
}

module_init(mymod_init);
module_exit(mymod_exit);
