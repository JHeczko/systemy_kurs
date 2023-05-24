#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <sys/semaphore.h>
#include <sys/sem.h>
#include <fcntl.h>
#include "semaphore.h"

using namespace std;

//konsturktory
Semaphore::Semaphore(const char* name,int flags, mode_t mode, unsigned int value) : name(name), value(value), mode(mode), flags(flags){
}

Semaphore::~Semaphore(){
}


int Semaphore::openSem(){
    if(name == nullptr){
        perror("No name was given");
        return -1;
    }
    sem_t* adres = sem_open(name, flags);
    this->sem_adress = adres;
    if(adres == SEM_FAILED){
        perror("SEM_OPEN FAILED");
        return -1;
    }
    else{
        return 0;
    }
}

int Semaphore::createSem(){
    if(name == nullptr){
        perror("No name was given");
        return -1;
    }
    sem_t* adres = sem_open(name, flags, mode, value);
    this->sem_adress = adres;
    if(adres == SEM_FAILED){
        perror("SEM_OPEN FAILED");
        return -1;
    }
    else{
        return 0;
    }
}

int Semaphore::closeSem(){
    if(sem_close(sem_adress) == -1){
        perror("CLOSE FAILURE");
        return -1;
    }
    else{
        return 0;
    }
}

int Semaphore::deleteSem(){
    while(sem_unlink(name) != -1);
    return 0;
}

int Semaphore::waitSem(){
    if(sem_wait(sem_adress)){
        perror("WAIT FAILURE");
        return -1;
    }
    else{
        return 0;
    }
}

int Semaphore::postSem(){
    if(sem_post(sem_adress)){
        perror("POST FAILURE");
        return -1;
    }
    else{
        return 0;
    }
}
