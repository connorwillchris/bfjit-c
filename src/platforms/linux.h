#ifndef LINUX_H
#define LINUX_H

/*
#define ALLOC_FUNC(x) mmap(x)
#define FREE_FUNC(x) munmap(x)
*/

void* alloc(const int bytes);

void dealloc(void* p, const int bytes);

#endif
