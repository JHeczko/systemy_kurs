#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
    
int main(){
    int n = 0;
    if(mkfifo("./pipe", 0664) == 0){
        printf("PIPE OK\n");
        }
    else{
        printf("%s\n", strerror(errno));
        exit(EXIT_FAILURE);
        }
    while(n != -1){
        printf("Aby usunąć potok wpisz \"-1\" :");
        scanf("%d", &n);
    }
    system("rm ./pipe");

}
