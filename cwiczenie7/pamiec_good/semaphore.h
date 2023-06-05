#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sys/semaphore.h>
#include <sys/sem.h>
#include <fcntl.h>



namespace semaphore{
    sem_t* open_sem(const char *name, int oflag, mode_t mode = -1, unsigned int value = 999);
    int close_sem(sem_t *sem);
    int unlink_sem(const char *name);
    int post_sem(sem_t *sem);
    int wait_sem(sem_t *sem);
    int getvalue_sem(sem_t *sem, int *sval); 
}

/*

sem t *sem open(const char *name, int oflag); 
sem t *sem open(const char *name, int oflag, mode t mode, unsigned int value);
int sem close(sem t *sem);
int sem unlink(const char *name);
int sem post(sem t *sem);
int sem wait(sem t *sem);
int sem getvalue(sem t *sem, int *sval);

*/