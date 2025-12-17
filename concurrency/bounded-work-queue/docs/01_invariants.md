# Bounded Work Queue — Invariants

These invariants must hold at all times, even under concurrency.

## Structural
1. `0 <= size <= capacity`
2. `head` and `tail` indices are always within `[0, capacity)`
3. Queue storage is not accessed out of bounds

## Behavioral
4. Enqueue blocks if `size == capacity`
5. Dequeue blocks if `size == 0`
6. Items are dequeued in FIFO order
7. No item is lost or duplicated

## Concurrency
8. All queue mutations are mutually exclusive
9. Memory written by a producer before enqueue
   is visible to the consumer after dequeue

## Progress & Liveness

10. If producers continue to enqueue and consumers continue to dequeue,
    then enqueued items will eventually be dequeued (no deadlock).

11. If the queue is full and a consumer dequeues an item,
    at least one blocked producer is eventually unblocked.

12. If the queue is empty and a producer enqueues an item,
    at least one blocked consumer is eventually unblocked.

13. The implementation makes no starvation guarantees beyond those
    provided by the underlying scheduler.

## API & Ownership

14. The queue does not take ownership of enqueued items.
    Memory management is the caller's responsibility.

15. The queue stores and returns opaque pointers (`void *`).

16. Destroying the queue while threads are blocked is undefined behavior.

