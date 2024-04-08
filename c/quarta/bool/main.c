#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

void successful_termination(void);
bool is_even(int *);

int main (void) {

    atexit(successful_termination);
    for (int i = 1; i <= MAX; i++) {

            is_even(&i) ? printf("%2d: even\n", i) : printf("%2d: odd\t\t", i);

    }

    return 0;

}

bool is_even(int *num) {

    return ( (*num) % 2 == 0 ? true : false);

}

void successful_termination(void) {

    puts("\n\nProgram terminated succesfully");
    return;

}
