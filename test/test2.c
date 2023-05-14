#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

void func(int *arr){
    *arr = 4;
}

int main(){
    int arr[4] = {1,2,3,3};
    func(&arr[2]);
    printf("%d", arr[2]);
}