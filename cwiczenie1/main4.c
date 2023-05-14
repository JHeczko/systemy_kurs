#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int it = 1;


int main(){
    int pid = getpid();
    int arr[8][3];
    arr[0][0] = getpid();
    arr[0][1] = getppid();
    arr[0][2] = getpgid(getpid());
    system("clear");
    printf("1)id uzytkownika: %d\n2)id grupy uzy: %d\n3)id procesu: %d\n4)id procesu macierzystego: %d\n5)id grupy procesow: %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(getppid()));
    printf("\n");
    int i = 0;
    for(i=0; i<3; i++){
        int id = fork();
        switch(id){
            case -1:
                perror("Cos nie dziala\n");
                exit(1);
            case 0:
                /*arr[0][0] = getpid();
                arr[0][1] = getppid();
                arr[0][2] = getpgid(getpid());*/
                printf("%d)POTOMNY: ID:%d GID:%d PPID:%d\n",i, getpid(),getpgid(getpid()),getppid());
                sleep(1);
                break;
            default:
                sleep(2);
                //printf("%d)MACIERZYSTY: TWORZY: %d ID:%d GID:%d PPID:%d\n",i, id, getpid(), getpgid(getpid()), getppid());
                break;
        }
        if (pid == getpid()){
            sleep(5);
            printf("\n");
        }

    }
    printf("%dKONIEC PROGRAMU: ID: %d\n", it,getpid()); 
    }
