## Question 1

Describe Function of **pthread_create**:

- Usage: Create a new thread. Compile and link with `-pthread`.

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                  void *(*start_routine) (void *), void *arg);
  ```

- Arguments:

  - The `*thread` parameter is a pointer to the thread identifier.
  - The `*attr` parameter is a pointer to the `pthread_attr_t`, which used to set the thread attributes.
  - The `*start_routine` parameter is the starting address of the thread running function.
  - The `*arg` parameter is the parameter of the running function.

## Question 2

Describe Function of **pthread_join**:

- Usage: The `pthread_join()` function waits for the thread specified by thread to terminate. If that thread has already terminated, then pthread_join() returns immediately. The thread specified by thread must be joinable. Compile and link with `-pthread`. It returns 0 if succeed, otherwise it returns error code.

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_join(pthread_t thread, void **retval);
  ```

- Arguments:

  - `thread`: thread identifier.
  - `retval`: pointer to a variable used to store the returned value of the thread.

## Question 3

Describe Function of **pthread_mutex_lock**:

- Usage:
  The mutex object referenced by mutex shall be locked by calling `pthread_mutex_lock()`. If the mutex is already locked, the calling thread shall block until the mutex becomes available. This operation shall return with the mutex object referenced by mutex in the locked state with the calling thread as its owner.

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_mutex_lock(pthread_mutex_t *mutex);
  ```

- Arguments:
  
  - `*mutex`: the pointer to the mutex to be locked.

## Question 4

Describe Function of **pthread_cond_wait**:

- Usage:
  The `pthread_cond_wait()` functions shall block on a condition variable. They shall be called with mutex locked by the calling thread or undefined behavior results.

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
  ```

- Arguments:

  - `*cond`: a pointer to a condition variable. This function will wait for the condition to become signaled.
  - `*mutex`: a pointer to a mutex, which is used to avoid race.

## Question 5

Describe Function of **pthread_cond_signal**:

- Usage:
  The `pthread_cond_signal()` function shall unblock at least one of the threads that are blocked on the specified condition variable cond (if any threads are blocked on cond).

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_cond_signal(pthread_cond_t *cond);
  ```

- Arguments:

  - `*cond`: a pointer to a condition variable. This function will signal the condition variable.
  - `*mutex`: a pointer to a mutex, which is used to avoid race.

## Question 6

Describe Function of **pthread_mutex_unlock**:

- Usage:
  The `pthread_mutex_unlock()` function shall release the mutex object referenced by mutex. The manner in which a mutex is released is dependent upon the mutex's type attribute. If there are threads blocked on the mutex object referenced by mutex when `pthread_mutex_unlock()` is called, resulting in the mutex becoming available, the scheduling policy shall determine which thread shall acquire the mutex.

- Prototype:

  ```c
  #include <pthread.h>

  int pthread_mutex_lock(pthread_mutex_t *mutex);
  ```

## Question 7

Describe Function of **sem_open** :

- Usage:
  The mutex object referenced by mutex shall be locked by calling `pthread_mutex_lock()`. If the mutex is already locked, the calling thread shall block until the mutex becomes available. This operation shall return with the mutex object referenced by mutex in the locked state with the calling thread as its owner.

- Prototype:

  ```c
  #include <fcntl.h>           /* For O_* constants */
  #include <sys/stat.h>        /* For mode constants */
  #include <semaphore.h>

  sem_t *sem_open(const char *name, int oflag);
  sem_t *sem_open(const char *name, int oflag,
                  mode_t mode, unsigned int value);
  ```

## Question 8

Describe Function of **sem_wait** :

- Usage:
  `sem_wait()` decrements (locks) the semaphore pointed to by sem. If
  the semaphore's value is greater than zero, then the decrement
  proceeds, and the function returns, immediately. If the semaphore
  currently has the value zero, then the call blocks until either it
  becomes possible to perform the decrement (i.e., the semaphore value
  rises above zero), or a signal handler interrupts the call.

- Prototype:

  ```c
  #include <semaphore.h>

  int sem_wait(sem_t *sem);
  ```

## Question 9

Describe Function of **sem_post** ：

- Usage:

`sem_post()` increments (unlocks) the semaphore pointed to by sem. If the semaphore's value consequently becomes greater than zero, then another process or thread blocked in a sem_wait(3) call will be woken up and proceed to lock the semaphore.

- Prototype:

```c
#include <semaphore.h>

int sem_post(sem_t *sem);
```

## Question 10

Describe Function of **sem_close** ：

`sem_close()` closes the named semaphore referred to by sem, allowing any resources that the system has allocated to the calling process for this semaphore to be freed.

- Prototype:

```c
#include <semaphore.h>

int sem_close(sem_t *sem);
```

## Question 11

Producer-Consumer Problem（understand producer_consumer.c）: Are the data that consumers read from the buffer are produced by the same producer?

Yes, but if there are multiple producers, the data that one specific consumer reads may be from multiple producers.

## Question 12

Producer-Consumer Problem（understand producer_consumer.c）: What is the order of the consumer's read operations and the producer's write operations, and their relationship

If the queue is full, the producer will wait for the consumer to consume data, (which will release a new space).

If the queue is empty, the consumer will wait for the producer to produce data, (which will release a new space).

In other situation, the order is unsure (because it is preemptive)

## Question 13

Producer-Consumer Problem（understand producer_consumer.c）: Briefly describe the result of the program

Keep watching the status of the producer, the queue and the consumer.

More details:

After every round (in a producer execusion or in a consumer execution), it will output a information in format:

`[X]<---| a | b | c | | | | | | |<---[Y]`

In this case,

- `X` is the data what the consumer consumed, blank for nothing.
- `Y` is the data what the producer produced, blank for nothing.
- `a`~`z` is the data in the queue.

`X` and `Y` will not appear at the same time, because they can not execute at the same time because of the mutex.

## Question 14

Producer-Consumer Problem（understand producer_consumer.c）: What queue is used in this program, and its characteristics?

It's a shared ring buffer, which means:

- It may be accessed at the same time without a lock because it's shared.
- It can store at most `N` elements.
- It can push or pop an element in `O(1)`

## Question 15

Producer-Consumer Problem（understand producer_consumer.c）: Briefly describe the mutual exclusion mechanism of this program.

There are two mutual executions, `producer` and `consumer`.

`producer` and `consumer` both will acquire a mutex lock before they do their own jobs.

- `producer` (after acquiring a mutex lock):

  - if the queue is full, the producer will wait until the queue becomes not full.
  - if the queue is empty, the producer will release the mutex lock and notify the consumer to consume the data.
  - otherwise, it will push a random item onto the queue, and printing the status of the queue.

- `consumer` (after acquiring a mutex lock):

  - if the queue is empty, the consumer will wait until the queue becomes not full.
  - if the queue is full, the consumer will release the mutex lock and notify the producer to produce a data.
  - otherwise, it will pop a item from head of the queue, and printing the status of the queue.
