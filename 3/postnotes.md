Common use of atomic operations
===============================

	A common use of the atomic integer operations is to implement counters
	Protecting a sole counter with a complex locking scheme is overkill, so instead developers use 
	atomic_inc() and atomic_dec(), which are much lighter in weight.
