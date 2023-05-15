#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "semaphore.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <string>

using namespace std;

int Semaphore::readNumber(){
    string s;
    plik.seekg(0, ios::beg);
    plik.seekp(0, ios::beg);
    getline(plik, s);
    #ifdef DEBUG
        cout << "READ NUBMER: " << stoi(s) << endl;
    #endif
    return 1;
}

void Semaphore::writeNumber(int i){
    #ifdef DEBUG
        cout << "Write number: " << i << endl;
    #endif 
    plik.seekg(0, ios::beg);
    plik.seekp(0, ios::beg);
    plik << i;
}
//konsturktory
Semaphore::Semaphore(const char* path, int value) : path(path), value(value){
}

Semaphore::~Semaphore(){
}
//end konstruktory
int Semaphore::createSem(){
    #ifdef DEBUG
        cout << "--------CREATESUM: " << value << endl;
    #endif
    int des = open(path, O_CREAT | O_EXCL | O_RDWR, 0644);
    if(des){
        close(des);
        plik.open(path, ios::out | ios::in | ios::trunc);
        writeNumber(value);
        plik.close();
        return 0;
    }
    else{
        close(des);
        return -1;
    }
    
}

int Semaphore::openSem(){
    plik.open(path, ios::out | ios::in);
    plik.seekg(0, ios::beg);
    plik.seekp(0, ios::beg);
    #ifdef DEBUG
        cout << "Opensem: " << getpid() << endl;
    #endif
    return plik.is_open();
}

int Semaphore::closeSem(){
    plik.close();
    return plik.is_open();
}

int Semaphore::deleteSem(){
    while(unlink(path) != -1);
    return 0;
}

int Semaphore::waitSem(){
    int i;
    while (true){
        i = readNumber();
        #ifdef DEBUG
            cout << "SEMWAIT: " << i << endl;
        #endif
        if(i == 0) {
            #ifdef DEBUG
                cout << "CZEKAM AZ ZWOLNI SIE SEMAFOR: " <<  getpid() << endl;
            #endif
        }
        else{
            #ifdef DEBUG
                cout << "SEMAFOR ZWOLNIONY WYKONUJE SWOJE DZIALANIE: " << getpid() << endl;
            #endif
            --i;
            writeNumber(i);
            break;
        }
        }
    return 0;
}

int Semaphore::postSem(){
    int i = readNumber();
    #ifdef DEBUG
        cout << "SEMPOST: " << i << endl;
    #endif
    writeNumber(i++);
    return 0;
}
