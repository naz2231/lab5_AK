#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/types.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK_Lab5");
MODULE_AUTHOR("Nazar Martyniuk IO-82");

EXPORT_SYMBOL(print_hello);

static int print_hello(uint count)
{
    int i;
    if (count == 0)
    {
        pr_warn("c = 0");
    }
    else if (count >= 5 && count <= 10)
    {
        pr_warn("5 < c < 10");
    }
    else if (count > 10)
    {
        pr_err("c > 10");
        return -EINVAL;
    }
    for (i = 0; i < count; i++)
    {
    pr_info("Hello, world\n");
    }
    return 0;
}

static int __init hello1_init(void)
{
    pr_info("Hello1 started");
    return 0;
}

static void __exit hello1_exit(void)
{
    pr_info("Hello1 finished");
}

module_init(hello1_init);
module_exit(hello1_exit);
