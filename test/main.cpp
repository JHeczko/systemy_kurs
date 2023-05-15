#include <string>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <fstream>

using namespace std;

int main(){
    int des = open("./plik.txt", O_RDWR | O_TRUNC, 0644);
    close(des);
    int liczba = 22;
    fstream plik;
    plik.open("./plik.txt", ios::in | ios::out | ios::trunc);
    plik.seekg(0, ios::beg);
    plik.seekp(0, ios::beg);
    plik << liczba;
        plik.seekg(0, ios::beg);
    plik.seekp(0, ios::beg);
    plik << 45;
    


}