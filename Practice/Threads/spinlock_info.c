/* Spinlock

   Most kernel locking is implemented with spinlocks. 
   Unlike semaphores, spinlocks may be used in code that cannot sleep
     (e.g. interrupt handlers). 
   Spinlocks can offer higher performance than semaphores in general.
   But they are subject to a different set of constraints.

   A mutual exclusion device ("locked" or "unlocked"). 
   Usually implemented as a single bit in an integer value. 
   Code wishing to take out a particular lock tests the relevant bit. 
   If the lock is available, the "locked" bit is set and the code 
      continues into the critical section. 
   Otherwise, the code goes into a tight loop where it repeatedly checks 
      the lock until it becomes available (hence the "spin" in spinlock).
   There may be several spinning locks on the same variable - this could
      cause a problem on hyperthreaded processors.  In this case, the real 
      CPU's resources (pipelines, etc) are shared by 2 (or more) logical 
      CPUs, and if one of these logical CPUs is spinning it can waste 
      resources that could have been used by the other logical CPU. To 
      reduce this problem Intel introduced the PAUSE instruction, which 
      is meant to be used in tight polling loops (like spinlocks). 

   Note: on a uniprocessor, spinning would go on forever starving everyone

   Major constraint: the critical section holding the spinlock must be
   atomic.  It cannot sleep.  It must be guaranteed to reach the
   unlock.  otherwise some other piece of code that takes the
   processor while the critical section is sleeping may try to get the
   lock and it cannot do that.

   For example, suppose:
    1. a device driver takes out a lock that controls access to its device
    2. while the lock is held, the device issues an interrupt 
    3. the IH must also obtain the lock before accessing the device (spins)
    4. the IH is executing on the same processor as the driver
   Then:
    while the interrupt handler is spinning, the non-interrupt code will 
    not be able to run to release the lock.  That processor will spin forever.

   Thus, there must be a way to disable interrupts on the local CPU while 
   holding a lock.

   When the kernel holds a spinlock, pre-emption is disabled!

   Note: just about all memory operations require some kind of suspension.
   Writing code that will execute under a spinlock requires paying 
   attention to every function that you call.

   Major constraint: the locked code must finish as fast as it possibly can!
   Otherwise, perhaps even the CPU scheduler is in trouble!

   functions to obtain a lock:
     void spin_lock(spinlock_t *lock);
     void spin_lock_irqsave(spinlock_t *lock, unsigned long flags);
     void spin_lock_irq(spinlock_t *lock);
     void spin_lock_bh(spinlock_t *lock)

   - irqsave disables interrupts on the local CPU before taking the spinlock
     the previous interrupt state is stored in 'flags'.
   - irq does not worry about the flags - can be used ONLY if the coder is 
     sure that nothing else has disabled interrupts in the meantime.
   - bh disables software interrupts but does not disable hardware interrupts

   functions to release a lock:
     void spin_unlock(spinlock_t *lock);
     void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);
     void spin_unlock_irq(spinlock_t *lock);
     void spin_unlock_bh(spinlock_t *lock);
   
   these must be invoked in correspondence with the functions that took the lock
*/
#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <sys/time.h>

#define LOOPS 10000000

int list[LOOPS];
int idx = 0;
int cs1 = 0, cs2 = 0;

pthread_spinlock_t spinlock;
 
pid_t gettid() { return syscall( __NR_gettid ); }
 
void *consumer(void *ptr) {
   printf("Consumer TID %lu\n", (unsigned long)gettid());

   while (1) {
      pthread_spin_lock(&spinlock);
      if (idx >= LOOPS) {
         pthread_spin_unlock(&spinlock);
         break;
      }
      list[idx++] += 1;
      pthread_spin_unlock(&spinlock);
      if ((int)ptr == 1) cs1++; else cs2++;
   }
   return NULL;
}

int main() {
   int i, lo_cnt = 0, hi_cnt = 0;
   pthread_t thr1, thr2;
   struct timeval tv1, tv2;
 
   pthread_spin_init(&spinlock, 0);
 
   // Creating the list content...
   for (i = 0; i < LOOPS; i++) list[i] = 0;

   // Measuring time before starting the threads...
   gettimeofday(&tv1, NULL);
   pthread_create(&thr1, NULL, consumer, (void*)1);
   pthread_create(&thr2, NULL, consumer, (void*)2);

   pthread_join(thr1, NULL);
   pthread_join(thr2, NULL);

   // Measuring time after threads finished...
   gettimeofday(&tv2, NULL);

   if (tv1.tv_usec > tv2.tv_usec) {
      tv2.tv_sec--;
      tv2.tv_usec += 1000000;
   }

   for (i=0 ; i < LOOPS ; i++) {
      if (list[i] == 0) {
         lo_cnt++;
         printf("lo:%d ",i);
      } else if (list[i] > 1) {
         hi_cnt++;
         printf("hi:%d ",i);
      }
   }
   printf("lo_cnt=%d hi_cnt=%d cs1=%d cs2=%d\n",lo_cnt,hi_cnt,cs1,cs2);

 
   printf("Time: %ld.%ld sec\n",tv2.tv_sec-tv1.tv_sec,tv2.tv_usec-tv1.tv_usec);
   return 0;
}