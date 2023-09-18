Atomic bit operations with return value
========================================

//Atomically set the bit nr in the location starting from p, and return old value at the nrth bit
int test_and_set_bit(unsigned int nr, volatile unsigned long *p);

//Atomically clear the bit nr in the location starting from p, and return old value at the nrthbit
int test_and_clear_bit(unsigned int nr, volatile unsigned long *p);

//Atomically flip the bit nr in the location starting from p, and return old value at the nrth bit
int test_and_change_bit(unsigned int nr, volatile unsigned long *p);
