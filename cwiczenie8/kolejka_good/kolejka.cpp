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
#include "kolejka.h"

using namespace std;

mqd_t queue::open_mq(const char *name, int oflag){
    mqd_t des = mq_open(name, oflag);
    if(des == ((mqd_t)-1)){
        perror("Open Failure - 2 args");
        return ((mqd_t)-1);
    }
    else
    {
        return des;
    }
};

mqd_t queue::open_mq(const char *name, int oflag, mode_t mode, struct mq_attr *attr){
    mqd_t des = mq_open(name, oflag, mode, attr);
    if(des == ((mqd_t)-1)){
        perror("Open Failure - 2 args");
        return ((mqd_t)-1);
    }
    else
    {
        return des;
    }
};
int queue::close_mq(mqd_t mqdes)
{
    if(mq_close(mqdes) == -1){
        perror("close error");
        return -1;
    }
    return 0;
}
int queue::unlink_mq(const char *name){
    return mq_unlink(name);
};

int queue::receive_mq(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio){
    if(mq_receive(mqdes, msg_ptr, msg_len, msg_prio) == -1){
        perror("Receive error");
        return -1;
    }
    return 0;
};

int queue::send_mq(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio){
    if(mq_send(mqdes, msg_ptr, msg_len, msg_prio) == -1){
        perror("send error");
        return -1;
    }
    return 0;
};

int queue::getattr_mq(mqd_t mqdes, struct mq_attr *attr){
    if(mq_getattr(mqdes, attr) == -1){
        perror("Getattr error");
        return -1;
    }
    return 0;
};

int queue::setattr_mq(mqd_t mqdes, struct mq_attr *newattr, struct mq_attr *oldattr){
    if(mq_setattr(mqdes, newattr, oldattr) == -1){
        perror("Setattr error");
        return -1;
    }
    return 0;
};