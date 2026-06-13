#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include "spsc_ring.h"

#define NUM_ITEMS 99999999

static spsc_ring_t ring;
static long values[NUM_ITEMS];

void *producer(void *arg){
  (void) arg;
  for(long i=0; i<NUM_ITEMS;i++){
    values[i]=i;
    while(!spsc_push(&ring, &values[i])){
      //a busy spin till there is space
    }
     }
  return NULL;
}

void *consumer(void *arg){
  (void)arg;
  for(long i=0;i<NUM_ITEMS;i++){
    void *item;
    while (!spsc_pop(&ring, &item)){
      //busy spin till there is data
      //
    }
    long val = *(long*)item;
    if(val != i ){
      printf("MISMATCH at index %ld: expected %ld, got %ld\n",i,i,val);
      exit(1);
    }
  }
  return NULL;
}

int main(void)
{
  assert(spsc_ring_init(&ring, 1024) == true);

  pthread_t prod_thread, const_thread;

  pthread_create(&prod_thread, NULL, producer, NULL);
  pthread_create(&const_thread,NULL, consumer,NULL);

  pthread_join(prod_thread,NULL);
  pthread_join(const_thread, NULL);


  spsc_ring_destroy(&ring);
  printf("all %d items passed through correctly, in order\n", NUM_ITEMS);

  return EXIT_SUCCESS;
}
