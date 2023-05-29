#include <iostream>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <algorithm>
#include <mqueue.h>
#include "kolejka.h"

using namespace std;

int main(){
    mq_attr attr;
    attr.mq_msgsize = 20;
    attr.mq_maxmsg = 5;
    Queue kolejka("/cos", O_CREAT, 0644, &attr);
    char buf[20];

    kolejka.create_q();

    kolejka.send_q("cos tam", 20, 1);

    //kolejka.receive_q(buf, 20, NULL);
    kolejka.close_q();

    kolejka.delete_q();


};