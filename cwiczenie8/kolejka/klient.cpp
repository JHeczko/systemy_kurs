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
#include <mqueue.h>
#include "header.h"

using namespace std;

void exitf(){
    int pid = getpid();
    string pids = to_string(pid);
    string nazwa("/");
    nazwa += pids;
    while(mq_unlink(nazwa.c_str()) != -1);
    cout << "Zamknalem: " << nazwa.data() << endl;   
    exit(EXIT_SUCCESS);
}

void handler(int id){
    int pid = getpid();
    string pids = to_string(pid);
    string nazwa("/");
    nazwa += pids;
    while(mq_unlink(nazwa.c_str()) != -1);
    cout << "Obsluzylem i usunalem sygnal o numerze: " << id << endl;
    exit(EXIT_SUCCESS);
}

int main(){
//SETUP 
    int pid = getpid();
    mq_attr attrK;
    attrK.mq_flags = 0;
    attrK.mq_maxmsg = 5;
    attrK.mq_msgsize = 20; 
    
    cout << getpid() << endl;

    string pids = to_string(pid);
    string nazwa("/");
    nazwa += pids;
    cout << nazwa.c_str() << endl;

    mqd_t desK = mq_open(nazwa.c_str(), O_CREAT | O_RDONLY | O_EXCL, 0644, &attrK );
    if(desK == -1){
        perror("mq_open failure K");
        exit(EXIT_FAILURE);
    }

    mqd_t desS = mq_open(SERWER_QUEUE, O_WRONLY);
    if(desS == -1){
        perror("mq_open failure S");
        exit(EXIT_FAILURE);
    }

    atexit(exitf);
    signal(SIGINT, handler);
/////////////////////////////////////

//WCZYTYWANIE Z KLAWIATURY
    string input{"cos"};
    string out;
    int licznik;
    int help;
    char buf[20];

    do{
            cout << "Prosze podac dzialanie: " << endl;
            getline(cin, input);
            if(input.length() == 0){
                exit(EXIT_SUCCESS);
            }
            while((help != string::npos) && input.length()){      
                help = input.find(' ');
                cout << help << endl;
                if(help >= 0){
                    input.erase(help, 1);
                }
            }
            cout << input << endl;
            out = pids +'|'+ input + '|';
            cout << out << endl;
            if(mq_send(desS, out.data(), 20, 1) == -1){
            perror("mqsend K error");
            }
            help = 0;
            out.erase();
            if(mq_receive(desK, buf, 20, NULL) == -1){
                perror("mq-receive KLIENT KONIEC\n");
            };
            cout << "WYNIK: "<< buf << endl;
    } while(input.length() != 0);
}