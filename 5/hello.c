#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    pr_info("%s: Value after initialization:%d\n", __func__, atomic_read(&val));
    atomic_set(&val, 4);
    pr_info("%s: Value after setting to 4:%d\n", __func__, atomic_read(&val));
    pr_info("%s: atomic_add_return(3):%d\n", __func__, atomic_add_return(3, &val));
    pr_info("%s: atomic_sub_return(2):%d\n", __func__, atomic_sub_return(2, &val));
    pr_info("%s: atomic_inc_return:%d\n", __func__, atomic_inc_return(&val));
    pr_info("%s: atomic_dec_return:%d\n", __func__, atomic_dec_return(&val));

    return -1;
}

static void test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
