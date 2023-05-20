#pragma once

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

#define SIZEBUF 20

using namespace std;

void wyjscie(){
    if(sem_unlink("semK") == -1){
        perror("UNLINK ERROR");
    }
    if(sem_unlink("semP") == -1){
        perror("UNLINK ERROR");
    }
    if(shm_unlink("mem") == -1){
        perror("UNLINK ERROR");
    }
    cout << "Usunalem" << endl;
}

void handler(int sig_id){
    if(sem_unlink("semK") == -1){
        perror("UNLINK ERROR");
    }
    if(sem_unlink("semP") == -1){
        perror("UNLINK ERROR");
    }
    if(shm_unlink("mem") == -1){
        perror("UNLINK ERROR");
    }
    cout << "Usunalem i odsluzylem sygnal: " << sig_id << endl;
}

struct buf_object{
    char arr_buf[SIZEBUF];
    int pos_write, pos_read;
};