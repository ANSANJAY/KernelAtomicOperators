Atomic Operation and test
=========================

int atomic_dec_and_test(atomic_t *i); //atomic Subtract 1 from *i and return 1 if the result is zero; 0 otherwise

int atomic_inc_and_test(atomic_t *i); //atomic Add 1 to *i and return 1 if the result is zero; 0 otherwise

// Atomically subtract val from *i and return 1 if the result is zero; otherwise 0
int atomic_sub_and_test(int val, atomic_t *i); 

//Atomically add val to *i and return 1 if the result is negative; otherwise 0
int atomic_add_negative(int val, atomic_t *i);


