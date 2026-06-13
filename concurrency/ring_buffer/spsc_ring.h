#ifndef SPSC_RING_H
#define SPSC_RING_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdalign.h>
#include <stdatomic.h>


typedef struct {
  void** buffer;
  alignas(64) _Atomic size_t head;
  alignas(64) _Atomic size_t tail;
  size_t capacity;
  size_t mask;
}spsc_ring_t;

bool spsc_ring_init(spsc_ring_t *ring, size_t capacity);
void spsc_ring_destroy(spsc_ring_t *ring);

bool spsc_is_full(const spsc_ring_t *ring);
bool spsc_is_empty(const spsc_ring_t *ring);
bool spsc_push(spsc_ring_t *ring, void *item);
bool spsc_pop(spsc_ring_t *ring, void** out_item);

#endif
