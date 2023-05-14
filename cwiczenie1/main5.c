#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("1)id uzytkownika: %d\n2)id grupy uzy: %d\n3)id procesu: %d\n4)id procesu macierzystego: %d\n5)id grupy procesow: %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(getppid()));
    int i = 0;
    for(i=0; i<3; i++){
        int id = fork();
        switch(id){
            case -1:
                perror("Cos nie dziala\n");
                exit(1);
            case 0:
                setpgid(getpid(), getpid());
                printf("POTOMNY: %d GRUPA: %d\n", getpid(), getpgid(getpid()));
                break;
            default:
                printf("MACIERZYSTY: %d\n", id);
                break;
        }
    }
}