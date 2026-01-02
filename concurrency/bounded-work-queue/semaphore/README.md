# Bounded Work Queue (Semaphore-Based)

A bounded, thread-safe, blocking work queue implemented in C using POSIX semaphores.

This implementation is intended for **learning and analysis of concurrency primitives**, with an explicit focus on **invariants, constraints, assumptions, and trade-offs** rather than feature completeness or ergonomics.

It is not intended to be a production-ready container.

---

## Scope

- Fixed-capacity FIFO queue
- Multiple producers, multiple consumers
- Blocking `push` / `pop` semantics
- POSIX semaphores used for coordination
- Internal state is opaque to users

---

## Design Intent

The queue is modeled as a system of **countable resources**:

- **Available slots** (remaining capacity)
- **Available items** (enqueued elements)

Progress is governed exclusively by **resource availability**, as enforced by semaphore operations.  
No explicit emptiness or fullness predicates are used for control flow.

Correctness depends on maintaining **strict balance** between semaphore operations and internal state transitions.

---

## Semantics of Internal State

The queue maintains internal bookkeeping state (e.g. indices, counters) to support correctness and debugging.

In particular:

- `capacity` is fixed at initialization and is authoritative.
- Semaphore counts are authoritative for availability and blocking behavior.
- `size`, if present, is a **synchronized, observational metric** only.

`size` must **never** be used to determine:
- whether the queue is empty or full
- whether an operation should block
- whether an item is available
-bq_size() returns a best-effort snapshot of the queue’s item count.
The returned value may be stale immediately and must not be used for synchronization or correctness

Removing `size` must not affect correctness.

---

## Invariants

The following invariants must **always hold**, across all thread interleavings:

- `0 ≤ size ≤ capacity` (observational invariant; not authoritative)
- Each successful `push` corresponds to exactly one successful `pop`
- No item is lost or duplicated
- Consumers never read from uninitialized slots
- Producers never overwrite unconsumed slots
- Semaphore operations remain balanced
- At all times:  
  **(available slots + available items) == capacity**
- Internal ring buffer indices remain within bounds

Violation of any invariant renders the implementation incorrect.

---

## API Contract (Informal)

- The queue is created with a fixed capacity.
- `push` blocks when no slots are available.
- `pop` blocks when no items are available.
- All operations are thread-safe.
- Items are stored as `void *`.
- Item ownership and lifetime are managed by the caller.
- Queue destruction semantics must be respected by the caller.

Exact semantics are defined in `bounded_queue.h`.

---

## Constraints Accepted

This design intentionally accepts the following constraints:

- Blocking behavior is tied directly to semaphore counts.
- Internal state transitions must remain tightly coupled to semaphore operations.
- Expressing complex or conditional wake-up logic is not supported.
- Misuse (e.g. unbalanced wait/post) can cause global deadlock.
- Debugging becomes difficult if semaphore counts drift from internal bookkeeping.

These constraints are inherent to semaphore-based coordination.

---

## Assumptions

This implementation assumes:

- POSIX semaphore operations are correct and atomic.
- Semaphore wake-ups are sufficiently fair (no permanent starvation).
- Threads may block indefinitely.
- Threads may be delayed arbitrarily by the scheduler.
- All semaphore waits and posts are correctly paired.
- Callers follow the documented API contract.

Breaking these assumptions breaks correctness.

---

## Trade-offs

The following trade-offs are explicitly accepted:

- Simpler blocking model in exchange for reduced expressiveness
- Resource-based coordination instead of explicit state predicates
- Higher discipline required to maintain invariant balance
- Reduced observability of internal state for users

This implementation optimizes for **clarity of constraints**, not flexibility.

---

## What This Implementation Does Not Support

By design, this queue does not provide:

- Wait-free or lock-free progress guarantees
- Fine-grained or conditional wake-up semantics
- Authoritative inspection of internal state without synchronization
- Automatic recovery from API misuse

These are ruled out by the chosen coordination model.

---

## Testing

The `tests/` directory includes:

- Single-threaded correctness tests
- Multi-producer / multi-consumer stress tests
- Sanitizer-backed tests where applicable

Tests focus on invariant preservation under concurrency.

---

## Common Failure Modes

This implementation is particularly sensitive to the following classes of errors:

- **Unbalanced semaphore operations**  
  Missing or extra `wait` / `post` calls can permanently block producers or consumers.

- **Incorrect initialization counts**  
  Initial semaphore values that do not exactly reflect capacity and emptiness violate invariants immediately.

- **State update ordering bugs**  
  Updating internal state before or after semaphore operations in the wrong order can expose inconsistent state.

- **Error-path leaks**  
  Failing to release a semaphore on early return or error leads to gradual loss of progress.

- **Destruction with active waiters**  
  Destroying the queue while threads are blocked on semaphores results in undefined behavior unless explicitly handled.

- **Silent invariant drift**  
  Semaphore counts may appear correct while internal indices or bookkeeping counters have diverged, making bugs difficult to diagnose.

These failure modes are inherent to semaphore-based coordination and must be addressed through strict discipline and testing.

---

## Intended Audience

- Engineers learning concurrency at the primitive level
- Readers interested in correctness constraints and trade-offs
- Those studying semaphore-based coordination patterns

This is a **teaching and analysis artifact**, not a general-purpose container.

