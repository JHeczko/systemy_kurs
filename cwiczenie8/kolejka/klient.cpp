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
    int pid = getpid();
    string pids = to_string(pid);
    string nazwa("/");
    nazwa += pids;
    //while(mq_unlink(nazwa.c_str()) != -1);
    cout << "Zamknalem: " << nazwa.data() << endl;   
    exit(EXIT_SUCCESS);
}

void handler(int id){
    int pid = getpid();
    string pids = to_string(pid);
    string nazwa("/");
    nazwa += pids;
    //while(mq_unlink(nazwa.c_str()) != -1);
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

/* Poniewaz macos to syf, to nie ma tutaj mqueue.h, wiec w repo to bedzie zakomentowane ale wystarczy odkomentowac i to skompilowac, gdzies gdzie ta biblioteka jest + trzeba dopisac #include <mqueue.h>

    mqd_t desK = mq_open(nazwa.c_str(), O_CREAT | O EXCL | O_RDONLY , 0644, &attrK );
    if(desK = (mqd_t)-1){
        perror("mq_open failure K");
        exit(EXIT_FAILURE;
    }

    mqd_t desS = mq_open(SERWER_QUEUE, O_WRONLY);
    if(desS = (mqd_t)-1){
        perror("mq_open failure S");
        exit(EXIT_FAILURE;
    }

*/
    atexit(exitf);
    signal(SIGINT, handler);
/////////////////////////////////////

//WCZYTYWANIE Z KLAWIATURY
    string input;
    string out;
    int licznik;
    int help;

    do{
        cout << "Prosze podac dzialanie: " << endl;
        getline(cin, input);
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
        //if(mq_send(desS, out.data(), 20, 1) == -1){
        //    perror("mqsend K error");
        //}
        help = 0;
        out.erase();
        ++licznik;
    } while(input.length() != 0);

    char buf[20];

    for(int i = 0; i < licznik; ++i){
        //mq_receive(desK, buf, 20, NULL);
        cout << buf << endl;
    }

}