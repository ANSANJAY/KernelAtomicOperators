Atomic Bitwise Operations
=============================

In addition to atomic integer operations, the kernel also provides a family of functions that operate at the bit level.

Header File: <asm/bitops.h>

These functions operate on generic pointer. There is no equivalent of the atomic integer atomic_t.

Arguments:
===========
	1. Bit Number: 0 - 31 for 32 bit machines and 0 - 63 for 64-bit machines
	2. Pointer with valid address

//Atomically set the bit nr in location starting from addr
void set_bit(int nr, volatile unsigned long *addr);

//Atomically clear the nr-th bit starting from addr.
void clear_bit(int nr, volatile unsigned long *addr);

//Atomically flip the value of the nr-th bit starting from addr.
void change_bit(int nr, volatile unsigned long *addr);
