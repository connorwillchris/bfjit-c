#include <stdio.h>
#include "bf.h"

int main(int argc, char** argv) {
    Bf* bf = bf_new(30000);

    if (argc != 2) {
        printf("Usage: %s [string]\n", argv[0]);
        return 1;
    }

    bf_dostring(bf, argv[1]);

    bf_close(bf);
    return 0;
}
