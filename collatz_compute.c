#define _POSIX_C_SOURCE  200809L

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <err.h>

/*
   Command line program that computes number of steps in a Collatz function
   for the first n numbers. Result is stored in a .results file in the csv format
   {input,steps}.
*/

// gcc -std=c99 -Werror -Wall collatz_compute.c -o compute && ./compute

int collatz_compute(int n) {
    if (n <= 0)
        return -1;

    int ctr = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        ctr++;
    }

    return ctr;
}

#define FILENAME ".results"

int main(int argc, char *argv[]) {
    int size = argc == 2 ? atoi(argv[1]) : 100;

    printf("Computation started ...\n");

    int fd = open(FILENAME, O_WRONLY | O_CREAT);
    if (fd == -1)
        err(1, "%s", FILENAME);

    for (int i = 1; i <= size; i++) {
        int result = collatz_compute(i);
        if (dprintf(fd, "%d,%d\n", i, result) == -1)
            err(1, NULL);
    }

    printf("Task complete.\n");

    return 0;
}