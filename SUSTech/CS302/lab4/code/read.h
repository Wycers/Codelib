#include "init.h"

void *reader(int *buffer) {
    // Reader should read the value of buffer
    // Reader cannot start to work when there is any writer working
    // You should implement this using semaphore


    //acquire lock
    sem_wait(&rc);
    readcount++;
    if (readcount == 1)
        sem_wait(&db);

    //release lock
    sem_post(&rc);

    /* perform the reading operation */
    // You should output this just after this thread gets semaphore
    printf("Reader gets sem\n");

    // you should output this just before this thread releases the semaphore
    printf("Reader reads %d and releases\n", *buffer);


    // acquire lock
    sem_wait(&rc);
    readcount--;
    if (readcount == 0)
        sem_post(&db);

    // release lock
    sem_post(&rc);

}

