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
    cout << argv[1] << " "<< argv[2]<< " " << argv[3] << " " << getpgid(getpid()) << endl;
    sem_t* des_semP = sem_open("/semP", O_RDWR);
    sem_t* des_semK = sem_open("/semK", O_RDWR);
    int des_mem = shm_open("sem",O_RDWR);
    int des_file = open("./towarP", O_RDWR, 0644);

    buf_object* objptr = (buf_object *)mmap(NULL, sizeof(buf_object), PROT_WRITE | PROT_READ , MAP_SHARED, des_mem, 0);

    //pisanie do bufora
    cout << "PROD" << endl;
    char bufor;
    int readI,j,i;
    while(true){
        cout << "PRZED czemu P";
       // sem_wait(des_semP);
        cout << "czemu P";
        if(objptr->pos_write < 10){
            i = 0;
            j = objptr->pos_write % 10;
        }
        else{
            i = 1;
            j = objptr->pos_write % 10;
        }
        readI = read(des_file, &bufor, 1);
        if(readI == 0){
            objptr->arr_buf[i][j] = '\0';
            cout << "KONIEC DLA PROD: " << i << " " << j <<  " " << objptr->arr_buf[i][j] << endl;
            //sem_post(des_semK);
            break;
        }
        objptr->arr_buf[i][j] = bufor;
        cout << "POZYCJA WRITE: " << objptr->pos_write << " i: " << i << " j: " << j << " BUFOR: " << bufor << endl;
        objptr->pos_write = (objptr->pos_write + 1) % 20;

        //sem_post(des_semK);
    }
    cout << "PO PEtlI";



}