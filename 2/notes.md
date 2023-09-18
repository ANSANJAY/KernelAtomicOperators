Atomic Operations
==================
The easiest way to prevent race conditions due to “read-modify-write” instructions is by ensuring that such operations are atomic at the chip level. 

Every such operation must be executed in a single instruction without being interrupted in the middle and avoiding accesses to the same memory location by other CPUs.

 Most CPU instruction set architectures define instruction opcodes that can perform atomic read-modify-write operations on a memory location. 

In general, special lock instructions are used to prevent the other processors in the system from working until the current processor has completed the next action


atomic_t
=========
When you write C code, you cannot guarantee that the compiler will use an atomic instruction for an operation like a = a + 1 or even for a + +.

Thus, the Linux kernel provides a special atomic_t type (an atomically accessible counter) and some special functions and macros that act on atomic_t variables

Header File: <asm/atomic.h>
typedef struct { volatile int counter; } atomic_t;

Why a new user defined data type atomic_t is needed?
======================================================

Because the atomic data types are ultimately implemented with normal C types, the kernel
encapsulates standard variables in a structure that can no longer be processed with normal operators
such as ++.


What happens to atomic variables when the kernel is compiled without SMP Support?
==================================================================================

it works the same way as for normal variables (only atomic_t encapsulation is observed) because there is no interference from other processors


