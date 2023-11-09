#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/errno.h>
#include "hello1.h"

MODULE_AUTHOR("Skorobagatko Ivan <ivanskorobagatko@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Lab4");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int param = 1;
module_param(param, uint, 0444);
MODULE_PARM_DESC(param, "Скільки разів вивести рядок 'Hello, world!'");

static int __init hello2_init(void)
{
	pr_info("hello2 module loaded\n");

	if (param == 0 || (param >= 5 && param <= 10)) {
		pr_warn("Невірне значення параметра.\n");
	} else if (param > 10) {
		pr_err("Невірне значення параметра. Модуль не завантажено.\n");
		return -EINVAL;
	}

	hello(param);

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Unloading hello2 module\n");
}

module_init(hello2_init);
module_exit(hello2_exit);