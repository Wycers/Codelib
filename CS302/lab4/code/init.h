#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include <sys/stat.h>

extern sem_t db, rc;
extern int readcount;