#include "semaphore.h"
#include <iostream>
#include <unistd.h>


using namespace std;


int main(){
    Semaphore sem("./nazwa1");
    sem.createSem();
    sleep(4);
    switch(fork()){
        case -1:
            exit(EXIT_FAILURE);
        case 0:
            sem.openSem();
            sem.waitSem();
            sleep(3);
            sem.postSem();
            cout << "Wykonal sie child" << endl;
            sem.closeSem();
            _exit(0);
        default:
            sem.openSem();
            sem.waitSem();
            sleep(2);
            sem.postSem();
            cout << "wykonal sie parent" << endl;
            wait(NULL);
            sleep(7);
            sem.closeSem();
            sem.deleteSem();
            exit(0);

    }

}