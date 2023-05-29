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
#include <string.h>
#include <algorithm>
//#include <mqueue.h>
#include "header.h"

using namespace std;

void exitf(){
    //while(mq_unlink(SERWER_QUEUE) != -1);
    cout << "Zamknalem serwer" << endl;   
    exit(EXIT_SUCCESS);
}

void handler(int id){
    //while(mq_unlink(SERWER_QUEUE) != -1);
    cout << "Obsluzylem i usunalem sygnal o numerze: " << id << endl;
    exit(EXIT_SUCCESS);
}

int main(){ 
//SETUP
    char buf[20] = {"23123|23/123.23|"};
    mq_attr attrS;
    attrS.mq_flags = 0;
    attrS.mq_maxmsg = 5;
    attrS.mq_msgsize = 20; 
/* Poniewaz macos to syf, to nie ma tutaj mqueue.h, wiec w repo to bedzie zakomentowane ale wystarczy odkomentowac i to skompilowac, gdzies gdzie ta biblioteka jest + trzeba dopisac #include <mqueue.h>

    mqd_t desS = mq_open(SERWER_QUEUE, O_CREAT | O EXCL | O_RDONLY , 0644, &attrS) ;
    if(desS = (mqd_t)-1){
        perror("mq_open failure S-side");
        exit(EXIT_FAILURE;
    }

*/
///////////////////////

// WYWOLANIE PROCESOW
    int id = {0};
    for(int i = 0; i<4; ++i){
        //id=fork();
        switch(id){
            case -1:{
                exit(EXIT_FAILURE);
            }
            case 0:{
                //execlp("./klient.x", "klient.x", (char *) NULL);
                break;
            }
            default:{
                break;
            }
            }}
/////////////////////////////////

// ZCZYTANIE 

int i = 0;
double liczba1I, liczba2I, wynik;
string pid, nazwa;
string liczba1, liczba2;
string znak;
string wynikS;
int flag = 0;
//mqd_t desK;

while(1){
    // //if(mq_receive(desS, buf, 20, NULL) == -1){
    //     perror("mq receive error in SERWER - SIDE");
    // };
    while(buf[i] != '|'){
        pid += buf[i];
        ++i;
    }
    ++i;

    #ifdef DEBUG
        cout << pid << "i: " << i << endl;
    #endif

    while(buf[i] != '|'){
        #ifdef DEBUG
        cout << "i: " << buf[i] << " " << i << endl;
        #endif
        switch(buf[i]){
            case '+':
            case '-':
            case '/':
            case '*':
                znak += buf[i];
                flag = 1;
                break;
            default:
                if(flag){
                    liczba1 += buf[i];
                }
                else{
                    liczba2 += buf[i];
                }
                break;
        }
        ++i;
    }    
    liczba1I = stod(liczba1);
    liczba2I = stod(liczba2);
    cout << "Liczba1: " << liczba1I << " Znak: " << znak << " Liczba2: " << liczba2I << endl;

    switch(*(znak.data())){
        case '+':
            cout << "DODAWANIE +\n";
            wynik = liczba1I + liczba2I;
            break;
        case '-':
            cout << "ODEJMOWANIE -\n";
            wynik = liczba1I - liczba2I;
            break;
        case '/':
            cout << "DZIELENIE /\n";
            wynik = liczba1I / liczba2I;
            break;
        case '*':
            cout << "MNOZENIE *\n";
            wynik = liczba1I * liczba2I;
            break;
}

    #ifdef DEBUG
        cout << "WYNIK: " << wynik << endl;
    #endif
    wynikS = to_string(wynik);
    #ifdef DEBUG
        cout << "WYNIKS: " <<wynikS << endl;
    #endif

    nazwa += '/' + pid;
    #ifdef DEBUG
        cout << "NAZWA: " << nazwa << endl;
    #endif
    // desK = mq_open(nazwa, O_WRONLY) ;
    // if(desK = (mqd_t)-1){
    //     perror("mq_open failure S-side");
    //     exit(EXIT_FAILURE;
    // }
    //if(mq_send(desK, wynikS.data(), 20, 1) == -1){
    //    perror("mqsend SERWER error");
    //}

i = 0;
pid.erase(); 
nazwa.erase();
liczba1.erase();
liczba2.erase();
znak.erase();
wynikS.erase();
flag = 0;
    break;
}
}