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

