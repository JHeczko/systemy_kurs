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
#include "main.h"

using namespace std;

void wyjscie(){
    while(sem_unlink("/semP") != -1);
    while(sem_unlink("/semK") != -1);
    while(shm_unlink("/mem") != -1);
    cout << "Usunalem" << endl;
}

void handler(int sig_id){
    while(sem_unlink("/semP") != -1);
    while(sem_unlink("/semK") != -1);
    while(shm_unlink("/mem") != -1);
    cout << "Usunalem i odsluzylem sygnal: " << sig_id << endl;
}

int main(int argc, char* argv[]){
//------------------SETUP
    // while(sem_unlink("/semP") != -1);
    // while(sem_unlink("/semK") != -1);
    // while(shm_unlink("/mem") != -1);
    unsigned int a = 20;
    unsigned int b = 0; 
    sem_t* des_semP = sem_open("/semP", O_CREAT | O_EXCL, 0644, a);
    sem_t* des_semK = sem_open("/semK", O_CREAT | O_EXCL, 0644, b);
    int des_mem = shm_open("/mem", O_CREAT | O_RDWR | O_EXCL | O_TRUNC, 0644);
    atexit(wyjscie);
    signal(SIGINT, handler);
    int valueK,valueP;
    // sem_getvalue(des_semK ,&valueK);
    // sem_getvalue(des_semP ,&valueP);

    // cout << "VALUE OF SEMP AND SEMK: " << valueP << " " << valueK << endl;
    cout << "DES SHM: " << des_mem << endl << "SIZE: " << sizeof(buf_object) << endl;

    ftruncate(des_mem, sizeof(buf_object));

    buf_object* bufptr = (buf_object*) mmap(NULL, sizeof(buf_object), PROT_WRITE | PROT_READ , MAP_SHARED, des_mem, 0);
    bufptr->pos_read = 0;
    bufptr->pos_write = 0;
    munmap(bufptr, sizeof(buf_object));
//------------------KONIEC SETUP
//------------------OBSLUGA BLEDU
    if(des_semK == SEM_FAILED){
        exit(EXIT_FAILURE);
    }
    else if(des_mem == -1){
        exit(EXIT_FAILURE);
    }
    else if(des_semP == SEM_FAILED){
        exit(EXIT_FAILURE);
    }
//------------------KONIEC OBLSUGI BLEDU
//-----------------WYWOLANIE PROCESOW
    for(int i = 0; i < 2; ++i){
        int id = fork();
        switch(id){
            case -1:{
                perror("Fork failure");
                exit(EXIT_FAILURE);
            }
            case 0:{
                if(i == 0){execlp("./kons", "kons", "/mem", "/semK", "./towarK.txt",(char *) NULL);};
                if(i == 1){execlp("./prod", "prod", "/mem", "/semP", "./towarP.txt",(char *) NULL);};
                break;
            }
            default:{
                break;
            }
        }
    }
    
    wait(NULL);
    wait(NULL);
    #ifdef DEBUG
        cout << "Poczekalem\n";
    #endif 

}