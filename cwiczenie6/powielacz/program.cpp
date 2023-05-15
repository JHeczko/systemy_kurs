#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    do {
        cout << "Cos robie nie w SK: " << getpid() << endl;
        sleep(2);
        
    }
    while(1);
}