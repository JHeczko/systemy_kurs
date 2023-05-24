// binary semaphore S = 1; // Semafor binarny do synchronizacji procesow
// // Proces P_i
//   do {
//      // Wlasne sprawy
//      PB(S);
//      // Sekcja krytyczna
//      VB(S);
//      // Reszta
//   } while (1);

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string>
#include <signal.h>

using namespace std;
// argv[1] = ilosc procesow do odpalenia; argv[2] = sciezka procesu do odpalenia, argv[3] = ilosc sekscji krytycznych
void wyjscie(){
    while((sem_unlink("/semafor1")) != -1);
   // while(unlink("./plik.txt"));
}

void handler(int n){
    while((sem_unlink("/semafor1")) != -1);
    while(unlink("./plik.txt"));
    cout << "Przechwycony i oblsuzony sygnal o num: " << n << endl;
}

int main(int argc, char* argv[]){
    atexit(wyjscie);
    signal(SIGINT, handler);
    int des = open("./plik.txt", O_CREAT | O_TRUNC | O_RDWR | O_CREAT, 0644);
    char a = '1';
    write(des, &a, 1);
    close(des);

    string s1 = argv[3]; // ilosc sekcji krytycznych
    string s2 = argv[1]; // ilosc procesow do odpalenia
    unsigned int n = stoi(s2);
    sem_t* sem = sem_open("/semafor1", O_CREAT | O_EXCL, 0644, 1);
    if(sem == SEM_FAILED){
        exit(EXIT_FAILURE);
    }
    #ifdef DEBUG
        cout << "Parent: " << sem << endl;
    #endif
    
    for(int i = 0; i < n; i++){
        int id = fork();
        switch(id){
            case -1:
                cout << "Nie dziala"<<endl; 
                exit(EXIT_FAILURE);
            case 0:
                execlp(argv[2], argv[2], argv[3], (char*)NULL);
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < n; ++i){
        wait(NULL); //zabawne jest to, ze tutaj ta petla z wait dziala
    }
    des = open("./plik.txt", O_RDONLY, 0644);
    char buf2;
    int buf3;
    lseek(des,0,SEEK_SET);
    read(des, &buf2, 1);
    close(des);
    cout << "Po calosci: " << buf2 << endl;
    sem_close(sem);
    exit(0);
}
