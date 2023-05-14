#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void obsluga_sygnalu(int n){
    printf("Witam, oblsuguje sygnal o numerze %d (SIGBUS) i czekam 2 sekundy\n", n);
    sleep(2);
}

int main(){
    printf("EXEC) PID: %d ||| Program do oblusgi sygnalow: 1) Operacja domyslna, 2) Zignorowanie sygnalu(SIGINT 2) 3) Własna oblsuga(SIGBUS 10)\n", getpid());
    if(signal(SIGBUS, obsluga_sygnalu) == SIG_ERR){
        perror("Cos nie tak z signalem");
        exit(EXIT_FAILURE);
    }
    if(signal(SIGINT, SIG_IGN) == SIG_ERR){
        perror("Cos nie tak z signalem");
        exit(EXIT_FAILURE);
    }
    pause();
    return 0;
}