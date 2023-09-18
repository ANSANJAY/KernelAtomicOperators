#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

unsigned long addr = 0x50;
MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    pr_info("Value before performing any atomic operations:%02lx\n", addr);
    set_bit(0, &addr);
    pr_info("Value after setting the 0'th bit:%02lx\n", addr);
    clear_bit(4, &addr);
    pr_info("Value after clearing the 4th bit:%02lx\n", addr);
    change_bit(0, &addr);
    pr_info("Value after changing the 0th bit:%02lx\n", addr);
    return -1;
}

static void test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
