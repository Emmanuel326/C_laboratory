#include <semaphore.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>


#include "bounded_queue.h"
#include "../common/ring_buffer.h"

 struct bounded_queue 
{
        struct ring_buffer rb;
        sem_t slots;
        pthread_mutex_t lock;
        sem_t items;

        

};


static int bq_init(bounded_queue *q, size_t capacity)
{
        if(q==NULL|| capacity==0 || capacity > SEM_VALUE_MAX)
                return -1;

        q->rb.capacity = capacity;
        q->rb.size     = 0;
        q->rb.head     = 0;
        q->rb.tail     = 0;

        q->rb.buffer = malloc(capacity* sizeof(void *));
        if(q->rb.buffer ==NULL)
                return -1;


        //a mutext to protect ring buffer mutation
        if(pthread_mutex_init(&q->lock, NULL) != 0)
        {
                free(q->rb.buffer);
                return -1;
        }
        


        
        if(sem_init(&q->slots,0, capacity)!=0)
        {
                pthread_mutex_destroy(&q->lock);
                free(q->rb.buffer);
                return -1;
        }
        
                

        if(sem_init(&q->items,0,0)!=0)
        {
                sem_destroy(&q->slots);
                pthread_mutex_destroy(&q->lock);
                free(q->rb.buffer);
                return -1;
        }

                
return 0;

}



bounded_queue_t *bq_create(size_t capacity)
{
    
    bounded_queue_t *q = malloc(sizeof(bounded_queue_t));
    if (q == NULL)
        return NULL:w
                ;

    
    if (bq_init(q, capacity) != 0) {
        free(q);  
        return NULL;
    }

    return q; 
}


size_t bq_capacity(const struct bounded_queue_t *q) {
    return q->rb.capacity;
}

size_t bq_size(const bounded_queue_t *q)
{


}
