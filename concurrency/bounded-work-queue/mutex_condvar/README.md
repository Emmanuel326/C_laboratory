## Mutex + Condition Variable Implementation

This directory contains a bounded work queue implementation using
`pthread_mutex_t` and `pthread_cond_t`.

This implementation satisfies the global invariants defined in:
`../docs/01_invariants.md`.

---

### Mechanism

- A single mutex protects all queue state (`size`, `head`, `tail`, buffer)
- Two condition variables are used:
  - `not_full` — producers wait when the queue is full
  - `not_empty` — consumers wait when the queue is empty
- All waits are performed in `while` loops to handle spurious wakeups

---

### Guarantees

- FIFO ordering
- Blocking enqueue when full
- Blocking dequeue when empty
- No busy waiting

---

### Tradeoffs

- Simple and easy to reason about
- Threads may sleep → higher latency under contention
- Fairness depends on the OS scheduler

### Verification Suite (Survival Verified)

This implementation has been subjected to aggressive testing to ensure safety and liveness:

1. **Functional Correctness**: Single-threaded tests verify FIFO ordering and circular buffer wrap-around logic.
2. **High-Contention Stress Test**: 
   - 4 Producers, 4 Consumers, 40,000 items.
   - Verified via Sum-Checksum (expected vs actual) to ensure **zero data loss** or duplication.
3. **Dynamic Analysis (Sanitizers)**:
   - **ASan (AddressSanitizer)**: Verified zero memory leaks and no out-of-bounds heap accesses.
   - **UBSan (UndefinedBehaviorSanitizer)**: Verified no integer overflows or non-compliant pointer arithmetic.
   - **TSan (ThreadSanitizer)**: Verified **zero data races** across thousands of concurrent operations.

---

### Compilation & Testing

To compile with all safety checks:
```bash
clang -g -O2 -Wall -Wextra -Werror -fsanitize=address,undefined \
    tests/test_stress.c bounded_queue.c -I. -I../common -lpthread -o stress_test
