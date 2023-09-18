More atomic operations
========================
//Atomically adds val to i and return pre-addition value at i
int atomic_fetch_add(int val, atomic_t *i);


//Atomically subtracts val from i, and return pre-subtract value at i
int atomic_fetch_sub(int val, atomic_t *v);


//Reads the value at location i, and checks if it is equal to old; if true, swaps value at v with new, and always returns value read at i

int atomic_cmpxchg(atomic_t *i, int old, int new);

//Swaps the oldvalue stored at location i with new, and returns old value i
int atomic_xchg(atomic_t *i, int new);

