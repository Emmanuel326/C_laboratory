#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

#include "../bounded_queue.h"

static bounded_queue_t q;
static int consumer_returned = 0;

void *consumer_thread(void *arg)
{
        (void)arg; //lets keep it unused
    void *item = NULL;

    /* This should BLOCK until producer enqueues */
    assert(bq_dequeue(&q, &item) == 0);

    consumer_returned = 1;
    assert(*(int *)item == 42);

    return NULL;
}

int main(void)
{
    pthread_t consumer;
    int value = 42;

    assert(bq_init(&q, 1) == 0);
    assert(bq_size(&q) == 0);

    /* Start consumer: should block */
    assert(pthread_create(&consumer, NULL, consumer_thread, NULL) == 0);

    /* Give consumer time to reach dequeue and block */
    sleep(1);

    /* Consumer must NOT have returned yet */
    assert(consumer_returned == 0);

    /* Enqueue item, should wake consumer */
    assert(bq_enqueue(&q, &value) == 0);

    /* Wait for consumer to finish */
    assert(pthread_join(consumer, NULL) == 0);

    /* Now consumer must have returned */
    assert(consumer_returned == 1);
    assert(bq_size(&q) == 0);

    bq_destroy(&q);

    printf("test_block_on_empty: PASS\n");
    return 0;
}

