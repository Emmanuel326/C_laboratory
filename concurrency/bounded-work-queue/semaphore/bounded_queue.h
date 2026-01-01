#pragma once
#include <stddef.h>

typedef struct bounded_queue bounded_queue_t;

//Api functions 
//create a bounded blockig queue with fixed capacity
//return NULL on failure
bounded_queue_t *bq_create(size_t capacity);

//Destroy a queue
//UB  if called while other threads are using or blocked on it
void bq_destroy(bounded_queue_t *q);

size_t bq_size(const bounded_queue_t *q);

size_t bq_capacity(const bounded_queue_t *q);

