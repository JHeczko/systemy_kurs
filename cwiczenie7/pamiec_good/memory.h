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

namespace sharedMemory{

int open_shm(const char *name, int flags, mode_t mode = 0);

int close_shm(int fd);

int ftruncate_shm(int fd, off_t length);

int unlink_shm(const char *name);

void* mmap_shm(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int munmap_shm(void *addr, size_t length);

}
/*

int shm open(const char *name, int flags, mode t mode);

int close(int fd);

int ftruncate(int fd, off t length);

int shm unlink(const char *name);

void *mmap(void *addr, size t length, int prot, int flags, int fd, off t offset);

int munmap(void *addr, size t length);

*/