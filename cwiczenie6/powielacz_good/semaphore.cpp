#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sys/semaphore.h>
#include <sys/sem.h>
#include <fcntl.h>
#include "semaphore.h"

sem_t* semaphore::open_sem(const char *name, int oflag, mode_t mode, unsigned int value){
if(value == 999){
    sem_t* des = sem_open(name, oflag);
    if(des ==SEM_FAILED){
        perror("open error");
        return SEM_FAILED;
    }
    return des;
}
else{
    sem_t* des = sem_open(name, oflag, mode, value);
    if(des == SEM_FAILED){
        perror("open error");
        return SEM_FAILED;
    }
    return des;
}
};

int semaphore::close_sem(sem_t *sem){
    if(sem_close(sem) == -1){
        perror("sem close error");
        return -1;
    }
    return 0;
};

int semaphore::unlink_sem(const char *name){
    if(sem_unlink(name) == -1){
        perror("sem unlink error");
        return -1;
    }
    return 0;
};

int semaphore::post_sem(sem_t *sem){
    if(sem_post(sem) == -1){
        perror("sem post error");
        return -1;
    }
    return 0;
};

int semaphore::wait_sem(sem_t *sem){
    if(sem_wait(sem) == -1){
        perror("sem wait error");
        return -1;
    }
    return 0;
};

int semaphore::getvalue_sem(sem_t *sem, int *sval){
    if(sem_getvalue(sem, sval) == -1){
        perror("sem getvalue error");
        return -1;
    }
    return 0;
}; 