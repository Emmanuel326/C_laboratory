#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../bounded_queue.h"

int main(void)
{
    bounded_queue_t q;
    const size_t capacity = 4;

    /* init */
    assert(bq_init(&q, capacity) == 0);
    assert(bq_capacity(&q) == capacity);
    assert(bq_size(&q) == 0);

    /* enqueue known values */
    int a = 1, b = 2, c = 3;

    assert(bq_enqueue(&q, &a) == 0);
    assert(bq_size(&q) == 1);

    assert(bq_enqueue(&q, &b) == 0);
    assert(bq_size(&q) == 2);

    assert(bq_enqueue(&q, &c) == 0);
    assert(bq_size(&q) == 3);

    /* dequeue and verify FIFO order */
    void *out;

    assert(bq_dequeue(&q, &out) == 0);
    assert(*(int *)out == 1);
    assert(bq_size(&q) == 2);

    assert(bq_dequeue(&q, &out) == 0);
    assert(*(int *)out == 2);
    assert(bq_size(&q) == 1);

    assert(bq_dequeue(&q, &out) == 0);
    assert(*(int *)out == 3);
    assert(bq_size(&q) == 0);

    /* cleanup */
    bq_destroy(&q);

    printf("test_single_thread_fifo: PASS\n");
    return 0;
}

