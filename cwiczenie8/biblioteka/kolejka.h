#pragma once

#include <iostream>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <algorithm>
#include <mqueue.h>

class Queue{
    public:
        Queue(const char* name, int flags, mode_t mode, mq_attr* attr);
        ~Queue(){};
        int create_q();
        int open_q();
        int close_q();
        int delete_q();
        int receive_q(char*, size_t, unsigned int *);
        int send_q(const char*, size_t, unsigned int);
        int getattr_q(mq_attr *);
        int setattr_q(mq_attr *, mq_attr *);

    private:
        const char* name; 
        int flags;
        mode_t mode; 
        mq_attr* attr;
        mqd_t des;
};

/*

mqd t mq open(const char *name, int oflag, mode t mode, struct mq attr *attr);

int mq_close(mqd t mqdes);

int mq unlink(const char *name);

int mq receive(mqd t mqdes, char *msg ptr, size t msg len, unsigned int *msg prio);

int mq send(mqd t mqdes, const char *msg ptr, size t msg len, unsigned int msg prio);

int mq getattr(mqd t mqdes, struct mq attr *attr);

int mq setattr(mqd t mqdes, struct mq attr *newattr, struct mq attr *oldattr);
*/