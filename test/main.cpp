#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main(){
    int des = open("./plik.txt", O_RDWR, 0644);
    char buf[20];
    while(read(des, buf, 20) != 0){
        for(int i = 0; i < 20; ++i){
            cout<<buf[i]<<endl;
        }
    };
    lseek(des,0,SEEK_SET);
    const char* cos = "0987654321";
    write(des, cos, 10);



}