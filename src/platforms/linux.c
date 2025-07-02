#include <sys/mman.h>
#include <stddef.h>
//#include <memory.h>

#include "linux.h"

void* alloc(const int bytes) {
    void* p = mmap(
        NULL,
        bytes,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    return p;
}

void dealloc(void* p, const int bytes) {
    munmap(p, bytes);
}