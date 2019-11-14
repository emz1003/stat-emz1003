#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat s;
    stat("makefile", &s);
    int bytes = s.st_size;
    printf("size in bytes: %lld\n", s.st_size);
    printf("mode: %o\n", s.st_mode);
    printf("time: %s\n", ctime(&s.st_mtime));

    printf("size in kilobytes: %.5lf\n", bytes / (float) 0b10000000000);
    printf("size in megabytes: %.5lf\n", bytes / (float) 0b11110100001001000000);
    printf("size in gigabytes: %.5lf\n", bytes / (float) 0x40000000);

    mode_t mode = s.st_mode - 0100000;
    int p[3];
    p[2] = mode % 010;
    p[1] = mode % 0100 / 010;
    p[0] = mode / 0100;
    // printf("mode: %o %o %o\n", user, group, other);
    printf("mode: ");
    int i;
    for(i = 0; i < 3; i++) {
        if (p[i] & 0b100)
            printf("r");
        else
            printf("-");

        if (p[i] & 0b10)
            printf("w");
        else
            printf("-");

        if (p[i] & 0b1)
            printf("x");
        else
            printf("-");
    }
    printf("\n");
}
