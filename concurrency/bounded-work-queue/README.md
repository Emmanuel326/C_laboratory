# Bounded Work Queue — Concurrency Lab in C

This directory explores one fundamental concurrency abstraction:
the **bounded work queue**.

The same queue is implemented using different synchronization
mechanisms to understand tradeoffs in:

- correctness vs performance
- blocking vs spinning
- fairness and backpressure
- memory visibility in C
- where lock-free and RCU approaches help — and where they don’t

This is not a single "best" implementation.
It is a study of invariants and mechanisms.

## Implementations

- `mutex_condvar/` — correctness baseline (blocking, sleeping)
- `semaphore/` — classic producer/consumer model
- `spinlock/` — low-latency, CPU-heavy
- `lockfree/` — atomic ring buffer
- `rcu_experiment/` — read-optimized exploration (educational)

## Structure

- `common/` — shared ring buffer and test utilities
- `docs/` — design notes and invariants
- `benchmarks/` — simple throughput/latency comparisons

## Why bounded queues?

Bounded queues appear in:
- thread pools
- schedulers
- network stacks
- logging pipelines
- OS kernels

They are simple to describe and notoriously easy to get wrong.

This lab focuses on *why*.

