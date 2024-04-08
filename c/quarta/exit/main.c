#include <stdio.h>
#include <stdlib.h>

void function(void);
void print_at_exit(void);

int main (void) {

    puts("Assigning a function to execute at exit");
    atexit(print_at_exit);
    puts("Executing ...");

    puts("Entering a func ...");
    function();

    puts("If you see this the program is now terminating through a return");

    return 0;

}

void function(void) {

    int choice = 0;
    puts("What to do?\n1. Exit\n2. Continue to main");
    do {
        scanf("%d", &choice);
    } while (choice < 1 || choice > 2);

    choice == 1 ? exit(EXIT_SUCCESS) : puts("Continuing to main ...");

    return;

}

void print_at_exit(void) {

    puts("Exit reached ...");

    return;
}
