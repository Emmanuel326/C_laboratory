#include <semaphore.h>
#include <stdlib.h>
#include <assert.h>


#include "bounded_queue.h"
#include "../common/ring_buffer.h"

typedef bounded_queue 
{
        struct ring_buffer rb;
        sem_t slots;
        sem_t items;

        

}bounded_queue;


int bq_init(bounded_queue *q, size_t capacity)
{
        if(q==NULL)
                return -1;
        if(capacity==0)
                return -1;
        q->rb.capacity=capacity;
        q->rb.buffer=malloc(capacity*sizeof(void*));
        if(q->rb.buffer==NULL)
                
                return -1;
        q->rb.size=0;
        q->rb.head=0;
        q->rb.tail=0;


        if (capacity > SEM_VALUE_MAX)
        return -1;


        
        if(sem_init(&q->slots,0, capacity)!=0)
        {
                free(q->rb.buffer);
                return -1;
        }
        
                

        if(sem_init(&q->items,0,0)!=0)
        {
                sem_destroy(&q->slots);
                free(q->rb.buffer);
                return -1;
        }
                




}
