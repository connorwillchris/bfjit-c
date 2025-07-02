#include <stdio.h>
#include "bf.h"

struct Brainfuck {
    char* tape;
    size_t len;
};

static int execute_no_jit(const char* s, Bf* b) {
    size_t p = 0;
    //size_t loops = 0;
    char* pc = s;
    char* ptr = b->tape;

    while (*pc) {
        switch (*pc) {
            case '>': ptr++; break;
            case '<': ptr--; break;
            case '+': (*ptr)++; break;
            case '-': (*ptr)--; break;
            case '.': putchar(*ptr); break;
            case ',': *ptr = getchar(); break;
            case '[': {
                if (!*ptr) {
                    int loop = 1;
                    while (loop > 0) {
                        pc++;
                        if (*pc == '[') loop++;
                        else if (*pc == ']') loop--;
                    }
                }
                break;
            }
            case ']': {
                if (*ptr) {
                    int loop = 1;
                    while (loop > 0) {
                        pc--;
                        if (*pc == '[') loop--;
                        else if (*pc == ']') loop++;
                    }
                }
                break;
            }
        }

        pc++;
    }

    return 0;
}

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

int bf_dostring(Bf* bstate, const char* s) {
    execute_no_jit(s, bstate);

    return 0;
}
