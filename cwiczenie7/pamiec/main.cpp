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


int main(int argc, char* argv[]){
//------------------SETUP
    sem_t* des_semP = sem_open("sem", O_CREAT | O_RDWR | O_EXCL | O_TRUNC, 0644, 1);
    sem_t* des_semK = sem_open("sem", O_CREAT | O_RDWR | O_EXCL | O_TRUNC, 0644, 1);
    int des_mem = shm_open("mem", O_CREAT | O_RDWR | O_EXCL | O_TRUNC, 0644);
    
    ftruncate(des_mem, sizeof(buf_object));

    buf_object* bufptr = (buf_object*)mmap(NULL, sizeof(buf_object), PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED, des_mem, 0);
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
    atexit(wyjscie);
    signal(SIGINT, handler);
//-----------------WYWOLANIE PROCESOW
    for(int i = 0; i < 2; ++i){
        int id = fork();
        switch(id){
            case -1:{
                perror("Fork failure");
                exit(EXIT_FAILURE);
            }
            case 0:{
                if(i == 0){execlp("./kons", "./kons",(char*) NULL);};
                if(i == 1){execlp("./prod", "./prod", (char*) NULL);};
            }
            default:{

            }
        }
    }
    for(int i = 0; i < 2; ++i){
        wait(NULL);
    }

}