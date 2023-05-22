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
#include "class.h"

using namespace std;

int sharedMemory::openShm(int flags, mode_t mode){
    int desbuf = open(name, flags, mode);
    this->des = desbuf;
    return desbuf;
};

int sharedMemory::closeShm(){
    return close(des);
};

int sharedMemory::delShm(){
    if(unlink(name) == -1){
        return -1;
    }
    while(unlink(name) != -1);
    return 0;
};