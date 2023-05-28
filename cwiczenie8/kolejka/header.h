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
#include <sys/msg.h>

#define SERWER_QUEUE "/serwerqueue"

struct mq_attr {
       long mq_flags;    // Opcje: 0 lub O_NONBLOCK
       long mq_maxmsg;   // Maksymalna liczba komunikatow w kolejce
       long mq_msgsize;  // Maksymalny rozmiar komunikatu (w bajtach)
       long mq_curmsgs;  // Liczba komunikatow aktualnie w kolejce
};


