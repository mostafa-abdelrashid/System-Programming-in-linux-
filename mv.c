#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }




    if (rename(argv[1], argv[2]) == -1) {
        perror("mv failed");
        return 1;
    }

    return 0;
}
