#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int main(){
    //tworzenie 4 procesow potomnych
    int pid[3];
    int info;
    int wpid;
    for(int i=0; i<3; i++){
            int id = fork();
            switch(id){
                case -1:
                    perror("Cos nie dziala\n");
                    exit(1);
                case 0:
                    printf("%d)POTOMNY: ID:%d GID:%d PPID:%d PGID: %d\n",i, getpid(),getpgid(getpid()),getppid(), getpgid(getpid()));
                    execlp("./z1.x", "z1.x", (char *) NULL);
                    exit(0);
                default:
                    pid[i] = id;
                    break;
            }
        }
        for(int k = 1; k<32; k++){ //funckja ktora sprawia ze program macierzysty ignoruje wszystkie sygnaly oprocz koniecznych
            signal(k, SIG_IGN);
        }

        wait(&info);
        if(errno == ESRCH){
            printf("%s", strerror(errno));
            exit(-1);
        }       
        int signalNumber1, signalNumber2, signalNumber3;
        printf("I proces id i status: %d %d II proces id i status:%d %d III proces id i status:%d %d \n", pid[0], info, pid[1], info, pid[2], info);
        if(WIFSIGNALED(info)){
            signalNumber1 = WTERMSIG(info);
            printf("Sygnal o numerze: %d , dokladna nazwa: %s\n", signalNumber1, strsignal(signalNumber1));  
        }
        if(WIFSIGNALED(info)){
            signalNumber2 = WTERMSIG(info);
            printf("Sygnal o numerze: %d , dokladna nazwa: %s\n", signalNumber2, strsignal(signalNumber2)); 
        }
        if(WIFSIGNALED(info)){
            signalNumber3 = WTERMSIG(info);
            printf("Sygnal o numerze: %d , dokladna nazwa: %s\n", signalNumber3, strsignal(signalNumber3));
        }
}