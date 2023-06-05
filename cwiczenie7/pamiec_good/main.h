#pragma once

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

#define SIZEBUF 10

using namespace std;

struct buf_object{
    char arr_buf[2][SIZEBUF];
    int pos_write, pos_read;
};

void nic(){

};