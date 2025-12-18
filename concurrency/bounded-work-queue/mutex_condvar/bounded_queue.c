#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "bounded_queue.h"

struct bounded_queue
{
        void **buffer;
        size_t capacity;
        size_t size;
        size_t head;
        size_t tail;

        pthread_mutex_t lock;
        pthread_cond_t not_full;
        pthread_cond_t not_empty;
};

int bq_init(bounded_queue_t *q , size_t capacity)
{
        if(!q || capacity==0)
        {
                return -1;
        }
        q->buffer=calloc(capacity, sizeof(void *));
        if(!q->buffer)
        {return -1;}

        q->capacity=capacity;
        q->size=0;
        q->head=0;
        q->tail=0;

        if(pthread_mutex_init(&q->lock,NULL) !=0)
                goto err_mutex;
        if(pthread_cond_init(&q->not_full, NULL)!=0)
                goto err_not_full;
        if(pthread_cond_init(&q->not_empty, NULL)!=0)
                goto err_not_empty;

        return 0;

err_not_empty:
    pthread_cond_destroy(&q->not_full);
err_not_full:
    pthread_mutex_destroy(&q->lock);
err_mutex:
    free(q->buffer);
    return -1;

}

void bq_destroy(bounded_queue_t *q)
{
        if(!q)
                return;

        pthread_cond_destroy(&q->not_empty);
        pthread_cond_destroy(&q->not_full);
        pthread_mutex_destroy(&q->lock);

        free(q->buffer);
}

