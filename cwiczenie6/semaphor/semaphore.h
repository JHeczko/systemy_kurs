#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace std;

class Semaphore{
    public:
        Semaphore(const char* path = nullptr, int value = 1);
        ~Semaphore();

        friend int createSem(int, const char*);
        int openSem();
        int waitSem();
        int postSem();
        int closeSem();
        int deleteSem();

        void writeNumber(int i);
        int readNumber();
        
    private:
        fstream plik;
        const char* path{nullptr};
        int value{0};


};

int createSem(int = 0, const char* = NULL);