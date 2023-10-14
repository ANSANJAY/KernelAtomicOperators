#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/atomic.h>

atomic64_t val = ATOMIC_INIT(0);
MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    pr_info("%s: Value after initialization:%lld\n", __func__, atomic64_read(&val));
    atomic64_set(&val, 4);
    pr_info("%s: Value after setting to 4:%lld\n", __func__, atomic64_read(&val));
    atomic64_dec(&val);
    pr_info("%s: Value after decrementing:%lld\n", __func__, atomic64_read(&val));
    atomic64_inc(&val);
    pr_info("%s: Value after incrementing:%lld\n", __func__, atomic64_read(&val));
    atomic64_add(3, &val);
    pr_info("%s: Value after adding 3:%lld\n", __func__, atomic64_read(&val));
    atomic64_sub(2, &val);
    pr_info("%s: Value after subtracting 2:%lld\n", __func__, atomic64_read(&val));
    return -1;
}

static void test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
