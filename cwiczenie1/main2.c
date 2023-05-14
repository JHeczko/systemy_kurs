#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    system("clear");
    printf("HALO: %d, %s, %s\n", argc, argv[1], argv[2]);
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
                sleep(1);
                //execlp("./", argv[1]);
                printf("%d)POTOMNY: ID:%d GID:%d PPID:%d\n",i, getpid(),getpgid(getpid()),getppid());
                break;
            default:
                wait(NULL);
                printf("%d)MACIERZYSTY: TWORZY: %d ID:%d GID:%d PPID:%d\n",i, id, getpid(), getpgid(getpid()), getppid());
                break;
        }
    }
    printf("KONIEC PROGRAMU: ID: %d\n", getpid());
}