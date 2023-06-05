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

namespace queue{

mqd_t open_mq(const char *name, int oflag);

mqd_t open_mq(const char *name, int oflag, mode_t mode, struct mq_attr *attr);

int close_mq(mqd_t mqdes);

int unlink_mq(const char *name);

int receive_mq(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);

int send_mq(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);

int getattr_mq(mqd_t mqdes, struct mq_attr *attr);

int setattr_mq(mqd_t mqdes, struct mq_attr *newattr, struct mq_attr *oldattr);

}