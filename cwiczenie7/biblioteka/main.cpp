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
#include "class.h"

using namespace std;

int main(){
    sharedMemory mem("./mem");
    char a = 'a';
    int des = mem.openShm(O_CREAT | O_RDWR, 0644);
    write(des, &a, 1);
    int* memory = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, des, 0);

    if(memory == MAP_FAILED){
        cout << "BLAD MAPOWANIA";
        exit(-1);
    }

    *memory = 4;

    cout << *memory;
    
    mem.closeShm();

    mem.delShm();

}