#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    printf("Witam z process.out:\n");
    printf("1)id uzytkownika: %d\n2)id grupy uzy: %d\n3)id procesu: %d\n4)id procesu macierzystego: %d\n5)id grupy procesow: %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(getppid()));
    printf("\n");
}