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



class Semaphore{
    public:
        Semaphore(const char* name = nullptr, int flags = 0, mode_t mode = 0, unsigned int value = 0);
        ~Semaphore();

        int createSem();
        int openSem();
        int waitSem();
        int postSem();
        int closeSem();
        int deleteSem();
        
    private:
        const char* name;
        int value;
        mode_t mode;
        int flags;
        sem_t* sem_adress;


};
