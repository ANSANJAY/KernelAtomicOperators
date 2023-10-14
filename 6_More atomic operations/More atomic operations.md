- **Extended Atomic Operations**
  - 🔄 **Atomic Fetch and Add/Subtract**: These operations provide both a **mutation and a retrieval in a single atomic action**, ensuring data consistency during concurrent access.
  - 🔄 **Atomic Compare and Swap (CAS) and Exchange**: These are sophisticated operations that ensure controlled modification under particular circumstances, offering robust synchronization mechanisms.

- **Function Summaries**
  - `atomic_fetch_add(val, &i)`: Add `val` to `i` and return the _previous_ value of `i`.
  - `atomic_fetch_sub(val, &i)`: Subtract `val` from `i` and return the _previous_ value of `i`.
  - `atomic_cmpxchg(&i, old, new)`: If `i` equals `old`, set `i` to `new`, always returning the initial value of `i`.
  - `atomic_xchg(&i, new)`: Swap the value of `i` with `new`, returning the _previous_ value of `i`.

### 🕵️‍♂️ 2. **Curious Questions** 🕵️‍♂️

- **Question 1**: How can `atomic_fetch_add` be utilized in a concurrent counter scenario, and why is returning the previous value useful?
  - **Answer**: In a multi-threaded counting application, `atomic_fetch_add` allows threads to increment the counter while simultaneously fetching the previous value, which can be used to understand the state of the counter right before our increment.

- **Question 2**: Why is the `atomic_cmpxchg` operation critical in concurrent programming, and can you provide a simple use case?
  - **Answer**: `atomic_cmpxchg` provides a mechanism to conditionally update a value, ensuring changes occur only under defined states, which prevents race conditions. A use case could be a multi-threaded ticket booking system where `atomic_cmpxchg` ensures that a seat is allocated only if it was in an expected available state.

- **Question 3**: How does `atomic_xchg` ensure data safety in a context where multiple threads are trying to update a shared variable?
  - **Answer**: `atomic_xchg` guarantees that the exchange of values is uninterrupted, ensuring that if multiple threads attempt to update a variable, each one will have an accurate, consistent view of its previous value, thereby preserving data integrity.

### 🍎 3. **Explain in Simple Words** 🍎

- **Imagine a Busy Shop 🏬**
  - 🍎 **Fetch and Add/Subtract** = You are a shopkeeper and after every sale, you update a sales board, but you also write down the previous number before changing it to keep track of each sale securely and precisely!
  - 🔄 **Compare and Swap** = Before writing the new number, you double-check that the current number is what you expect (no other sale happened in between). If it matches, you update; if not, you reassess.
  - 🔄 **Exchange** = You update the board with a new number, but you make sure to remember (return) the old number, so you always know exactly how much was sold when.

🍏 **Key Takeaways**:
- 📌 **Atomic Fetch Add/Subtract** = Add/Subtract & Remember the Previous State.
- 📌 **Compare and Swap** = Cautious, Conditional Updating.
- 📌 **Exchange** = Swap & Always Remember What Was There Before.