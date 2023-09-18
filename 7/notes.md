64-bit Atomic Operations
===========================

Many processor architectures have no 64-bit atomic instructions, but we need atomic64_t in order to support the perf_counter subsystem.

This adds an implementation of 64-bit atomic operations using hashed spinlocks to provide atomicity.

typedef struct {
	long long counter;
} atomic64_t;

These functions have the naming convention atomic64_*()
