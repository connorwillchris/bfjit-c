#ifndef BF_H
#define BF_H

#include <stddef.h>
#include <stdlib.h>

struct Brainfuck;
typedef struct Brainfuck Bf;

Bf* bf_new(size_t len);

void bf_close(Bf* bstate);

/*
Executes a given bf string and bf state.
*/
int bf_dostring(Bf* bstate, const char* s);

#endif
