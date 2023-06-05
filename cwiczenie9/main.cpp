#define _REENTRANT
#include <pthread.h>
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
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int GLOBAL_VAR = 0;
int CRITICAL_SECTION;
pthread_mutex_t mutexID;


/*
  =========================================================================
  Ustawienie pozycji kursora w punkcie o wspolrzednych (x,y) na ekranie,
  gdzie x - liczba kolumn (od lewej), y - liczba wierszy (od gory).
  Sekwencja \033[2K powoduje wymazanie poprzedniego napisu w danym wierszu.
  =========================================================================
*/
void gotoxy(unsigned x, unsigned y)
{
  printf("\033[%d;%dH\033[2K", y, x);
}


//=====================================================================================================================


void* watek(void * ptr){
    int * number = (int *)ptr;
    int pos = (*number) + 3;

    int czas = rand() % 3;

    gotoxy(1, pos);
    printf("[ ] - WATEK %d\n", *number);    

    if(pthread_mutex_lock(&mutexID) != 0){
        perror("Mutex lock error");
        exit(-1);
    };

    int licznik = GLOBAL_VAR;

    for(int i = 0; i < CRITICAL_SECTION; ++i){
        gotoxy(18, pos);
        printf("[X] - WATEK NUM: %d | NUMER SK: %d\n", *number, i); 
        ++licznik;
        sleep(1);
    }

    GLOBAL_VAR = licznik;

    sleep(czas);
    gotoxy(1, pos);
    printf("[ ] - WATEK NUM: %d | LOCAL COUNTER: %d\n", *number, licznik); 
    if(pthread_mutex_unlock(&mutexID) != 0){
        perror("Mutex unlock error");
        exit(-1);
    };

    return NULL;
}


//=====================================================================================================================


int main(int argc, const char* argv[]){

    printf("\033[5;7m");
    printf("    ---- Nacisnij klawisz [Enter], aby wystartowac! ----   ");
    getchar();
    printf("\033[0m");
    system("clear");
    printf("\033[1;4m"); 
// ==========SETUP==========================================================================================v
    string buf(argv[2]);
    CRITICAL_SECTION = stoi(buf);
    
    buf.clear();
    buf = argv[1];
    int len = stoi(buf);
    pthread_t pThread[len];

    if(pthread_mutex_init(&mutexID, NULL) != 0){
        perror("Mutex craeting error");
        exit(-1);
    }

// ===========CREATING THREADS=======================================================================================

    int numbers[len];
    for(int i = 0; i < len; ++i){
        numbers[i] = i;
        if(pthread_create(&pThread[i], NULL, watek, &numbers[i]) != 0){
            perror("pthread_create Failure");
        }
        //cout << i << ") " << pThread[i] << endl;
    }

    for (int i = 0; i<len;++i){
        if(pthread_join(pThread[i], NULL) != 0){
            perror("Pthread joun error");
        };
    }
    
    printf("\033[0m"); 
    pthread_mutex_destroy(&mutexID);
    system("clear");
    printf("\n");
    cout << "KONCOWA WARTOSC: " << GLOBAL_VAR << endl;
}