#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

unsigned long addr = 0x50;
atomic64_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    pr_info("Value before performing any atomic operations:%02lx\n", addr);
    pr_info("test_and_set_bit(0, addr):%d\n", test_and_set_bit(0, &addr));
    pr_info("Value before performing atomic operations:%02lx\n", addr);
    pr_info("test_and_clear_bit(0, addr):%d\n", test_and_clear_bit(0, &addr));
    pr_info("Value before performing atomic operations:%02lx\n", addr);
    pr_info("test_and_change_bit(0, addr):%d\n", test_and_change_bit(0, &addr));
    pr_info("Value before performing atomic operations:%02lx\n", addr);
    return -1;
}

static void test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
