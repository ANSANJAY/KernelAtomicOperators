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
    pr_info("%s: atomic_atomic_fetch_add(2):%d\n", __func__, atomic_fetch_add(2, &val));
    pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
    pr_info("%s: atomic_atomic_fetch_sub(1):%d\n", __func__, atomic_fetch_sub(1, &val));
    pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
    pr_info("%s: atomic_cmpxchg(2, 3):%d\n", __func__, atomic_cmpxchg(&val, 2, 3));
    pr_info("%s: atomic_cmpxchg(5, 3):%d\n", __func__, atomic_cmpxchg(&val, 5, 3));
    pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));
    pr_info("%s: atomic_xchg(5):%d\n", __func__, atomic_xchg(&val, 5));
    pr_info("%s: atomic_read:%d\n", __func__, atomic_read(&val));


    return -1;
}

static void test_hello_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
