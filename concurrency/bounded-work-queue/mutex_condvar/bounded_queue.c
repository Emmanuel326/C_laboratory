#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "bounded_queue.h"


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

int bq_enqueue(bounded_queue_t *q, void *item)
{
        if(!q)
                return -1;
        pthread_mutex_lock(&q->lock);

        //block while queue is full
        while(q->size==q->capacity)
        {
                pthread_cond_wait(&q->not_full, &q->lock);
        }

        //invariants that must hold inside the critical section
        assert(q->size<q->capacity);
        assert(q->tail<q->capacity);

        //enque a single item
        q->buffer[q->tail]=item;
        q->tail=(q->tail + 1)%q->capacity;
        q->size++;

        //queue is no longer empty; wake one consumer
        pthread_cond_signal(&q->not_empty);

        pthread_mutex_unlock(&q->lock);
        return 0;

}

int bq_dequeue(bounded_queue_t *q, void **item)
{
        if(!q || !item)
                return -1;

        pthread_mutex_lock(&q->lock);

        //block while queue is empty
        while(q->size==0)
        {
                pthread_cond_wait(&q->not_empty,&q->lock);
        }

        //invariants that must hold inside the critical section
        assert(q->size>0);
        assert(q->head<q->capacity);
        
        //dequeu the item
        *item=q->buffer[q->head];
        q->head=(q->head+1)%q->capacity;
        q->size--;

        //queue is no longer full; wake one producer
        pthread_cond_signal(&q->not_full);

        pthread_mutex_unlock(&q->lock);
        return 0;

}

size_t bq_capacity(bounded_queue_t *q)
{
        if(!q)
                return 0;
        return q->capacity;

}

size_t bq_size(bounded_queue_t *q)
{
        if(!q)
                return 0;
        pthread_mutex_lock(&q->lock);
        size_t size=q->size;
        pthread_mutex_unlock(&q->lock);

        return size;
}

