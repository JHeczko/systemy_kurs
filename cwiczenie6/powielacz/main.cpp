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
#include <fcntl.h>
#include <string>

using namespace std;
// argv[1] = ilosc procesow do odpalenia; argv[2] = sciezka procesu do odpalenia, argv[3] = ilosc sekscji krytycznych
void wyjscie(){
    sem_unlink("/semafor");
}

int main(int argc, char* argv[]){
    string s1 = argv[3];
    sem_t* sem = sem_open("/semafor", O_EXCL, 0644, stoi(s1));
    string s2 = argv[1];
    int n = stoi(s2);
    for(int i{0}; i < n; ++i){
        int id = fork();
        switch(id){
            case -1:
                exit(EXIT_FAILURE);
            case 0:
                execlp(argv[2], argv[2], (char*) NULL);
                break;
            default:

        }
    }
    atexit(wyjscie);
}
