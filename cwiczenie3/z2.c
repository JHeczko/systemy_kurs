#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>


int main(int argc, char *argv[]){
    int forkid = fork(); 
    //stworzenie procesu potomnego i wywolanie w nim funckji exec ktora otwiera program z zadania I
    if(forkid == 0){    
        if(execlp(argv[1], argv[1], (char *) NULL) == 0){
            perror("exec nie dziala\n");
        }

    }
    printf("Rodzic PID: %d\n", getpid());

    //sprawdzanie czy proces potomny exec istnieje
    if(kill(forkid, 0) == 0){
        printf("Proces istnieje\n");
    };
    if(errno == ESRCH){
       printf("%s", strerror(errno)); 
       exit(-1);
    }
    sleep(1);
    //wybor sygnalu ktory wyslemy
    int wybor;
    printf("Wybierz numer sygnalu od 1-16: ");
    scanf("%d", &wybor);

    if(wybor < 17 && wybor > 0){
        kill(forkid, wybor);
    }
    else{
        kill(forkid, 9);
        perror("Zly wybor");
        exit(-1);
    }

    

    //zaczekanie na proces a nastepnie zwrocenie zmiennej static_loc, ktora jest koniec czyli jego statusu wykonania
    int koniec;
    int signalNumber;
    wait(&koniec);
    printf("PID EXECU: %d, a takze jego status zakonczenia: %d\n",forkid, koniec);
    if(WIFSIGNALED(koniec)){
        signalNumber = WTERMSIG(koniec);
        printf("Sygnal o numerze: %d , dokladna nazwa: %s", signalNumber, strsignal(signalNumber));  //oczywiscie musimy dac inny sygnal niz ten ktory oblsugujemy wtedy dziala
    }

}
