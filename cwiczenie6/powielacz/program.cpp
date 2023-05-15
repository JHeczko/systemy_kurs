#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    sem_t* sem = sem_open("/semafor1", O_RDWR);
    if(sem == SEM_FAILED){
        cout << "Nie dziala";
        exit(-1);
    }
    do {
        sem_wait(sem);
        #ifdef DEBUG
            cout << "Potomny: " << sem <<endl;
            cout << "Cos robie nie w SK: " << getpid() << endl;
        #endif
        cout << "Robie cos w sekcji krytycznej: " << getpid() << endl;
        
        int des = open("./plik.txt", O_RDONLY, 0644);
        char buf2;
        int buf3;
        lseek(des,0,SEEK_SET);
        read(des, &buf2, 1);
        close(des);
        des = open("./plik.txt", O_WRONLY, 0644);
        lseek(des,0,SEEK_SET);
        buf3 = (int)buf2;
        buf3++;
        buf2 = (char)buf3;
        write(des, &buf2, 1);
        close(des);

        int n = rand() % 5;
        sleep(n);
        cout<< "Skonczylem sekcje krytyczna: "<< getpid() << endl;
        sem_post(sem);
        break;
    }
    while(1);
}