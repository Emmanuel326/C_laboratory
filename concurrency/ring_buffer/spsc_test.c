#include <stdio.h>
#include <assert.h>
#include "spsc_ring.h"

int main(void){
  spsc_ring_t ring;

  //reject non power of 2.
  assert(spsc_ring_init(&ring, 6)==false);
  printf("[ok] rejected non-power of 2 capacity\n");


  assert(spsc_ring_init(&ring, 4)==true);
  printf("[ok] init with capacity 4\n");

  //empty at start 
  assert(spsc_is_empty(&ring)==true);
  void *dummy;
  assert(spsc_pop(&ring, &dummy)==false);
  printf("pop on empty ring fails\n");

  //fill the ring up
  int values[4]={10,20,30,40};
  for (int i=0;i<4;i++) {
    assert(spsc_push(&ring,&values[i])==true);

  }
  printf("pushed 4 items\n");

  //should be full now 
  assert(spsc_is_full(&ring)==true);
  assert(spsc_push(&ring, &values[0])==false);
  printf("push on full  ring fails\n");

  //pop them back out check ordder(FIFO)
  for (int i=0;i<4 ; i++) {
    void *item;
    assert(spsc_pop(&ring, &item)==true);
    assert(*(int*)item == values[i]); 
  
  }
  printf("popped 4 items in FIFO order");

  //empty again
  assert(spsc_is_empty(&ring) ==true);
  printf("ring is empty after draining\n");

  spsc_ring_destroy(&ring);
  printf("\nall single-threaded tests passed\n");
  return 0;
}
