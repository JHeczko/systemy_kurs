#include "semaphore.h"
#include <iostream>
#include <unistd.h>


using namespace std;


int main(){
    createSem(0, "./nazwa1");
    int id = fork();
    switch(id){
        case -1:{
            exit(EXIT_FAILURE);}
        case 0:{
            Semaphore sem("./nazwa1");
            sem.openSem();
            sem.waitSem();
            sleep(3);
            sem.postSem();
            cout << "Wykonal sie child" << endl;
            sem.closeSem();
            _exit(0);
            break;}
        default:{
            Semaphore sem2("./nazwa1");
            sem2.openSem();
            sem2.postSem();
            sem2.waitSem();
            sleep(2);
            sem2.postSem();
            cout << "wykonal sie parent" << endl;
            wait(NULL);
            sleep(3);
            sem2.closeSem();
            sem2.deleteSem();
            exit(0);
            break;}
    }

}