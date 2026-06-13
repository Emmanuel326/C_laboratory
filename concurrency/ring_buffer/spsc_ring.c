#include "spsc_ring.h"
#include <stdlib.h>
#include <stdatomic.h>


bool spsc_ring_init(spsc_ring_t *ring, size_t capacity){
  if(capacity==0 || (capacity & (capacity -1)) !=0 ){return false;} //not a power of two

  ring->buffer =malloc(capacity * sizeof(void*));
  if(!ring->buffer){
    return false;
  }

  ring->capacity=capacity;
  ring->mask=capacity - 1;
  ring->head=0;
  ring->tail=0;

  return true;


}

void spsc_ring_destroy(spsc_ring_t *ring){
  free(ring->buffer);
  ring->buffer=NULL;
}

bool spsc_is_empty(const spsc_ring_t *ring){
  return ring->head==ring->tail;
}

bool spsc_is_full(const spsc_ring_t *ring){
  return (ring->tail - ring->head) == ring->capacity;
}

bool spsc_push(spsc_ring_t *ring, void* item){
  size_t tail=atomic_load_explicit(&ring->tail, memory_order_relaxed);
  size_t head=atomic_load_explicit(&ring->head, memory_order_acquire);
  if(tail-head == ring->capacity){
    return false;
  }
  size_t slot=tail & ring->mask;
  ring->buffer[slot]=item;
  atomic_store_explicit(&ring->tail, tail+1, memory_order_release);
  return true;
}

bool spsc_pop(spsc_ring_t *ring, void** out_item){
  size_t head = atomic_load_explicit(&ring->head, memory_order_relaxed);
  size_t tail = atomic_load_explicit(&ring->tail, memory_order_acquire);

  if(head==tail)
  {return false;}

  size_t slot = head&ring->mask;
  *out_item= ring->buffer[slot];

  atomic_store_explicit(&ring->head, head+1 ,memory_order_release);
  return true;



}
