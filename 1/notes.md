Atomic Operations
==================

Several assembly language instructions are of type “read-modify-write”
	they access a memory location twice,
		 the first time to read the old value and 
		 the second time to write a new value.

Suppose that two kernel control paths running on two CPUs try to “read-modify-write” the same memory location at the same time by executing nonatomic operations.

	At first, both CPUs try to read the same location, but the memory arbiter (a hardware circuit that serializes accesses to the RAM chips) steps in to grant access to one of them and delay the other.

	However, when the first read operation has completed, the delayed CPU reads exactly the same (old) value from the memory location.

	Both CPUs then try to write the same (new) value to the memory location; again, the bus memory access is serialized by the memory arbiter, and eventually both write operations succeed.

	However, the global result is incorrect because both CPUs write the same (new) value. Thus, the two interleaving “read-modify-write” operations act as a single one.

	Kernel Thread1				Kernel Thread2	
	------------------------------------------------------

	read i (5)
						read i(5)

	increment i(5 -> 6)	
		
						increment i (5 -> 6)

	write i(6)

						write i(6)
