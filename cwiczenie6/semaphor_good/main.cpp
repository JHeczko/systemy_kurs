#include "semaphore.h"
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>


using namespace std;


int main(){
    
    Semaphore create("/sem", O_CREAT | O_EXCL, 0644, 0);

    create.createSem();
    int id = fork();
    


    switch(id){
        case -1:{
            exit(EXIT_FAILURE);
        }
        case 0:{
            Semaphore sem1("/sem", O_RDWR);
            sem1.openSem();

            sem1.waitSem();
            cout << "Sekacja chikda\n";
            sleep(2);
            sem1.postSem();
        }    
        default:{
            Semaphore sem2("/sem", O_RDWR);
            sem2.openSem();

            sem2.waitSem();
            cout << "Sekckja parenta\n";
            sleep(2);
            sem2.postSem();
        }
    wait(NULL);
    create.closeSem();
    create.deleteSem();

}
}