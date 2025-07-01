#include "bf.h"

struct Brainfuck {
    char *tape;
    size_t len;
};

Bf * bf_new(size_t len) {
    Bf* b;
    char* tape = (char*)malloc(len * sizeof(char));
    b = (Bf*)malloc(1 * sizeof(Bf));

    b->len = len;
    b->tape = tape;

    return b;
}

void bf_close(Bf* bstate) {
    free(bstate->tape);
    free(bstate);
}