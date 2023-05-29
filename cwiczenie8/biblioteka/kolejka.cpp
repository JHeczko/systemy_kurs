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

Queue::Queue(const char* name, int flags, mode_t mode = 0, mq_attr* attr = NULL) : name(name) , mode(mode) , flags(flags) , attr(attr){

};

int Queue::create_q(){
        cout << this->attr << " "<< this->flags<< " " << this->mode<< " "  << this->name << endl;
        this->des = mq_open(name, flags, mode, attr);
        if(this->des == -1){
            perror("create failure");
            return -1;
        }
        return 0;
};

int Queue::open_q(){
    if(mq_open(name, flags) == -1){
        perror("Open failure");
        return -1;
    }
    return 0;
};

int Queue::close_q(){
    if(mq_close(this->des) == -1){
        perror("close failure");
        return -1;
    };
    return 0;

};

int Queue::delete_q(){
    while(mq_unlink(name) != -1);
    return 0;
};

int Queue::receive_q(char* msg_ptr, size_t msg_len, unsigned int *msg_prio = NULL){
    if(mq_receive(des, msg_ptr, msg_len, msg_prio) != -1){
        perror("receive ERROR");
        return -1;
    };
    return 0;
};

int Queue::send_q(const char* msg, size_t msg_len, unsigned int msg_prio){
    if(mq_send(des, msg, msg_len, msg_prio) != -1){
        perror("send ERROR");
        return -1;
    };
    return 0;
};

int Queue::getattr_q(mq_attr *attr){
    if(mq_getattr(des, attr) != -1){
        perror("get ERROR");
        return -1;
    };
    return 0;
};

int Queue::setattr_q(mq_attr *newattr, mq_attr *oldattr = NULL){
    if(mq_setattr(des, newattr, oldattr) != -1){
        perror("set ERROR");
        return -1;
    };
    return 0;
};
