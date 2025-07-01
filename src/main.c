#include "bf.h"

int main(int argc, char** argv) {
    Bf* bf = bf_new(50);
    bf_close(bf);

    return 0;
}
