#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define CHAR_TO_PRINT 'X'

int main() {
    int x = 0, y = 0;
    struct termios old, new;

    // Save the current terminal settings
    tcgetattr(STDIN_FILENO, &old);

    // Set the terminal to raw mode
    new = old;
    new.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    while (1) {
        // Clear the screen
        printf("\033[2J\033[1;1H");

        // Print the character at the current position
        printf("\033[%d;%dH%c", y + 1, x + 1, CHAR_TO_PRINT);

        // Get the user input
        int c = getchar();

        // Check for arrow keys
        switch (c) {
            case 65:  // Up arrow
                y--;
                break;
            case 66:  // Down arrow
                y++;
                break;
            case 67:  // Right arrow
                x++;
                break;
            case 68:  // Left arrow
                x--;
                break;
            case 3:   // Ctrl+C
                // Restore the terminal settings and exit
                tcsetattr(STDIN_FILENO, TCSANOW, &old);
                printf("\n");
                return 0;
        }
    }
}
