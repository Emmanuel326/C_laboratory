//spinlock is a simple yet specialized sychronization used in concuurent
//programming
//typically at systems or kernel level.
//it protects a shared resource from being accessed by multiple threads simultaneously
//
//
//

#include <stdatomic.h>

typedef struct
{
        atomic_int lock;

}spinlock_t;

//initialize
void spinlock_init(spinlock_t *l)
{
        atomic_store_explicit(&l->lock, 0, memory_order_relaxed);
}

//acquire
void spinlock_lock(spinlock_t, *l)
{

        while(atomic_exchange_explicit(&l->lock,1,memory_order_acquire)==1)
        {
                //spin
        }
}

//release or unlock
void spinlock_unlock(spinlock_t, *l)
{
        atomic_store_explicit(&l->lock,0,memory_order_release);
}

