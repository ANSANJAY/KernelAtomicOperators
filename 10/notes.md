Non atomic bitwise operations
===============================

Conveniently, nonatomic versions of all the bitwise functions are also provided.

They behave identically to their atomic siblings, except they do not guarantee atomicity, and their names are prefixed with double underscores.

For example, the nonatomic form of test_bit() is __test_bit().

If you do not require atomicity (say, for example, because a lock already protects your data), these variants of the bitwise functions might be faster.
