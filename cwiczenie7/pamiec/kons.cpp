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
    sem_t* des_semP = sem_open("semP", O_RDWR);
    sem_t* des_semK = sem_open("semK", O_RDWR);
    int des_mem = shm_open("mem",O_RDWR);
    int des_file = open("./towarK", O_RDWR, 0644);

    buf_object* objptr = (buf_object *)mmap(NULL, sizeof(buf_object), PROT_WRITE | PROT_READ , MAP_SHARED, des_mem, 0);

    cout << "KONS" << endl;
    int readI, i, j;
    char bufor;
    while(1){
        cout << "PRZED czemu K";
        //sem_wait(des_semK);
        cout << "czemu K";
        if(objptr->pos_read < 10){
            i = 0;
            j = objptr->pos_read % 10;
        }
        else{
            i = 1;
            j = objptr->pos_read % 10;
        }
        bufor = objptr->arr_buf[i][j];
        cout << "POZYCJA READ: " << objptr->pos_read << " i: " << i << " j: " << j << " BUFOR: " << bufor << endl;
        if(objptr->arr_buf[i][j] == '\0'){
            cout << "KONIEC DLA KONS: " << i << " " << j << endl;
            break;
        }
        objptr->pos_read = (objptr->pos_read + 1) % 20;
        write(des_file, &bufor, 1);
        //sem_post(des_semP);
    }
    cout << "PO PEtlI";
}