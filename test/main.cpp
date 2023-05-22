#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main(){
    int des = open("./plik.txt", O_RDWR, 0644);
    char buf;
    while(read(des, &buf, 1) != 0){
            cout<<buf<<endl;
            if(buf == '/0'){
                cout << "koneic";
            }
    };



}