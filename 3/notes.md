atomic_t
============

Initialization:
===================

atomic_t i;  //define i

atomic_t i = ATOMIC_INIT(1); //define i and initialize it to 1


Increment/Decrement
====================

void atomic_inc(atomic_t *i);  //Add 1 to *i
void atomic_dec(atomic_t *i);  //Subtract 1 from *i

Set/Read
========

void atomic_set(atomic_t *i, int j); //Atomically set counter i to value specified in j
int atomic_read(atomic_t *i); //Read value of the atomic counter i

Add/Sub
===========
void atomic_add(int val, atomic_t *i); //Atomically add val to atomic counter i
void atomic_sub(int val, atomic_t *i); //Atomically subtract val from atomic counter i




