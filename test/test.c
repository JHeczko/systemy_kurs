#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

int main(){
     int i = 0;
    for(i=0; i<3; i++){
        int id = fork();
        switch(id){
            case -1:
                perror("Cos nie dziala\n");
                exit(1);
            case 0:
                //execlp("./", argv[1]);
                printf("%d)POTOMNY: ID:%d GID:%d PPID:%d\n",i, getpid(),getpgid(getpid()),getppid());
                exit(0);
            default:
                //printf("%d)MACIERZYSTY: TWORZY: %d ID:%d GID:%d PPID:%d\n",i, id, getpid(), getpgid(getpid()), getppid());
                break;
        }
    }
    int j1,j2,j3,j4;
    j1 = wait(NULL);
    j2 =wait(NULL);
    j3 = wait(NULL);
    printf("%d %d %d", j1,j2,j3);
}