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

using namespace std;

class sharedMemory{
    public:
        sharedMemory(const char* nazwa) : name(nazwa){};

        int openShm(int, mode_t);
        int closeShm();
        int delShm();
    private:
        const char* name{nullptr};
        int des{-1};
};