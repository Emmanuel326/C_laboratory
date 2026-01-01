# Bounded Work Queue (Semaphore-Based)

A bounded, thread-safe, blocking work queue implemented in C using POSIX semaphores.
# Bounded Work Queue (Semaphore-Based)

A bounded, thread-safe, blocking work queue implemented in C using POSIX semaphores.

This implementation is intended for **learning and analysis of concurrency primitives**, with an explicit focus on **invariants, constraints, assumptions, and trade-offs**.

---

## Scope

- Fixed-capacity FIFO queue
- Multiple producers, multiple consumers
- Blocking semantics
- POSIX semaphores used for coordination
- Internal state is opaque to users

---

## Design Intent

This implementation models the queue as a set of **countable resources**:

- Available slots
- Available items

Progress is governed by **resource availability**, not by explicit predicate checks.

Correctness depends on maintaining strict balance between semaphore operations and internal state transitions.

---

## Invariants

The following invariants must **always hold**, across all thread interleavings:

- `0 ≤ size ≤ capacity` non negativity
- Each `push` corresponds to exactly one `pop`
- No item is lost or duplicated
- Consumers never read from uninitialized slots
- Producers never overwrite unconsumed slots
- Semaphore counts correctly reflect queue state
- Internal ring buffer indices remain within bounds
- empty slots + full tokens must sum up to  capacity

Violation of any invariant renders the implementation incorrect.

---

## API Contract (Informal)

- Queue is created with a fixed capacity.
- `push` blocks when the queue is full.
- `pop` blocks when the queue is empty.
- All operations are thread-safe.
- Items are stored as `void *`.
- Item ownership and lifetime are managed by the caller.
- Queue destruction semantics must be respected by the caller (see assumptions).

Exact semantics are defined in `bounded_queue.h`.

---

## Constraints Accepted

This design intentionally accepts the following constraints:

- Blocking behavior is tied directly to semaphore counts.
- Internal state transitions must remain tightly coupled to semaphore operations.
- Debugging is harder if semaphore counts drift from logical state.
- Expressing complex wake-up conditions is not supported.
- Misuse (unbalanced wait/post) can cause global deadlock.

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
- Higher discipline required from the implementation to maintain balance
- Reduced observability of internal state for users

This implementation optimizes for **clarity of constraints**, not flexibility.

---

## What This Implementation Does Not Support

By design, this queue does not provide:

- Wait-free or lock-free progress guarantees
- Fine-grained or conditional wake-up logic
- Safe inspection of internal state without synchronization
- Automatic recovery from misuse of the API

These are ruled out by the chosen model.

---

## Testing

The `tests/` directory includes:

- Single-threaded correctness tests
- Multi-producer / multi-consumer stress tests
- Sanitizer-backed tests where applicable

Tests focus on invariant preservation under concurrency.

---

## Intended Audience

- Engineers learning concurrency at the primitive level
- Readers interested in correctness constraints and trade-offs
- Those studying semaphore-based coordination patterns

This is not intended as a production-ready container.

---


## Scope

- Fixed-capacity FIFO queue
- Multiple producers, multiple consumers
- Blocking semantics
- POSIX semaphores used for coordination
- Internal state is opaque to users

---

## Design Intent

This implementation models the queue as a set of **countable resources**:

- Available slots
- Available items

Progress is governed by **resource availability**, not by explicit predicate checks.

Correctness depends on maintaining strict balance between semaphore operations and internal state transitions.

---

## Invariants

The following invariants must **always hold**, across all thread interleavings:

- `0 ≤ size ≤ capacity`
- Each `push` corresponds to exactly one `pop`
- No item is lost or duplicated
- Consumers never read from uninitialized slots
- Producers never overwrite unconsumed slots
- Semaphore counts correctly reflect queue state
- Internal ring buffer indices remain within bounds

Violation of any invariant renders the implementation incorrect.

---

## API Contract (Informal)

- Queue is created with a fixed capacity.
- `push` blocks when the queue is full.
- `pop` blocks when the queue is empty.
- All operations are thread-safe.
- Items are stored as `void *`.
- Item ownership and lifetime are managed by the caller.
- Queue destruction semantics must be respected by the caller (see assumptions).

Exact semantics are defined in `bounded_queue.h`.

---

## Constraints Accepted

This design intentionally accepts the following constraints:

- Blocking behavior is tied directly to semaphore counts.
- Internal state transitions must remain tightly coupled to semaphore operations.
- Debugging is harder if semaphore counts drift from logical state.
- Expressing complex wake-up conditions is not supported.
- Misuse (unbalanced wait/post) can cause global deadlock.

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
- Higher discipline required from the implementation to maintain balance
- Reduced observability of internal state for users

This implementation optimizes for **clarity of constraints**, not flexibility.

---

## What This Implementation Does Not Support

By design, this queue does not provide:

- Wait-free or lock-free progress guarantees
- Fine-grained or conditional wake-up logic
- Safe inspection of internal state without synchronization
- Automatic recovery from misuse of the API

These are ruled out by the chosen model.

---

## Testing

The `tests/` directory includes:

- Single-threaded correctness tests
- Multi-producer / multi-consumer stress tests
- Sanitizer-backed tests where applicable

Tests focus on invariant preservation under concurrency.

---

## Intended Audience

- Engineers learning concurrency at the primitive level
- Readers interested in correctness constraints and trade-offs
- Those studying semaphore-based coordination patterns

This is not intended as a production-ready container.

---


## Common Failure Modes

This implementation is particularly sensitive to the following classes of errors:

- **Unbalanced semaphore operations**  
  Missing or extra `post`/`wait` calls can permanently block producers or consumers.

- **Incorrect initialization counts**  
  Initial semaphore values that do not exactly reflect capacity and emptiness violate invariants immediately.

- **State update ordering bugs**  
  Updating internal state before or after semaphore operations in the wrong order can expose inconsistent state to other threads.

- **Error-path leaks**  
  Failing to release a semaphore on early return or error leads to gradual loss of progress.

- **Destruction with active waiters**  
  Destroying the queue while threads are blocked on semaphores can result in undefined behavior unless explicitly handled.

- **Silent invariant drift**  
  Semaphore counts may appear correct while internal indices or size counters have diverged, making bugs difficult to diagnose.

These failure modes are inherent to semaphore-based coordination and must be addressed through strict discipline and testing.

