#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(){
    int des = open("./plik.txt", O_RDWR | O_TRUNC, 0644);
    if(des == -1){
        cout << "Brak pliku";
    };
    char a = 'f';
    write(des, &a, 1);
    lseek(des, 0, SEEK_SET);
    write(des, &a, 1);
    lseek(des, 0, SEEK_SET);
    write(des, &a, 1);
    lseek(des, 0, SEEK_SET);
    write(des, &a, 1);
    lseek(des, 0, SEEK_SET);
    write(des, &a, 1);
    lseek(des, 0, SEEK_SET);
    write(des, &a, 1);




}