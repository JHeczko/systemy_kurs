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

    if(forkid == 0){
        setpgid(0, 0);
        execlp(argv[1], argv[1], (char *) NULL);
    }
    sleep(3);
    int pgid = getpgid(forkid);
    //sprawdzenie czy mamy wgl taki proces
    if(kill(-pgid, 0) == 0){
            printf("Proces istnieje\n");
        };
    if(errno == ESRCH){
        printf("%s", strerror(errno)); 
        exit(-1);
    }
    kill(-pgid, 9);
    int log=0;
    int pid = wait(&log);
    printf("LOG: %d PID: %d", log , pid);
}