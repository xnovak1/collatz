#include <stdlib.h>


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
    }

    return ctr;
}

int main(int argc, char *argv[]) {
    int size = argc == 2 ? atoi(argv[1]) : 100;
    
    printf("Printing the number of steps of Collatz function for the first %d numbers:\n", size);
    printf("--------------------------------------------------------------------------\n\n");

    printf("         i          |           result\n");
    printf("-------------------------------------------------\n")

    for (int i = 1; i < size; i++) {
        int result = collatz_compute(i);
        printf("%10d | %10d\n");
        printf("-------------------------------------------------\n");
    }

    return 0;
}