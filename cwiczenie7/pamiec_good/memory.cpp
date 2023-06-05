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
#include "memory.h"

using namespace std;

int sharedMemory::open_shm(const char *name, int flags, mode_t mode){
    int des;
    if(mode == 0){
        des = shm_open(name, flags);
        if(des == -1){
            perror("Open error - 2 arg");
            return -1;
       }
    }
    else{
       des = shm_open(name, flags, mode);
       if(des == -1){
        perror("Open error - 3 arg");
        return -1;
       }
    }
    return des;
};

int sharedMemory::close_shm(int fd){
    if(close(fd) == -1){
        perror("Clsoe error");
        return -1;
    }
    return 0;
};

int sharedMemory::ftruncate_shm(int fd, off_t length){
    if(ftruncate(fd, length) == -1){
        perror("Clsoe error");
        return -1;
    }
    return 0;
};

int sharedMemory::unlink_shm(const char *name){
    if(shm_unlink(name) == -1){
        perror("Unlink cant unlink");
        return -1;
    }
    return 0;
};

void* sharedMemory::mmap_shm(void *addr, size_t length, int prot, int flags, int fd, off_t offset){
    void* cos = mmap(addr, length ,prot, flags, fd, offset);
    if(cos == MAP_FAILED){
        perror("MAP FAILED");
        return MAP_FAILED;
    }
    return cos;
};

int sharedMemory::munmap_shm(void *addr, size_t length){
    if(munmap(addr, length) == -1){
        perror("MUNMAP FAILED");
        return -1;
    }
    return 0;
};

/*

int shm open(const char *name, int flags, mode t mode);

int close(int fd);

int ftruncate(int fd, off t length);

int shm unlink(const char *name);

void *mmap(void *addr, size t length, int prot, int flags, int fd, off t offset);

int munmap(void *addr, size t length);

*/