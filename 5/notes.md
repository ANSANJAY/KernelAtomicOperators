Atomic Add/Subtract and return
==============================

int atomic_add_return(int val, atomic_t *i);// Atomically add val to *i and return the result.
int atomic_sub_return(int val, atomic_t *i); // Atomically subtract val from *i and return the result.
int atomic_inc_return(atomic_t *i);// Atomically increment *i by one and return the result.
int atomic_dec_return(atomic_t *i);// Atomically decrement *i by one and return the result.


