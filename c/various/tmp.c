#include <stdio.h>

int power (int x, int y);

int main(void) {
       
    int x = 2;
    int y = 4;

    printf("%d", power(x, y));

    return 0;
}

int power (int x, int y) {
    if (y = 0) {
        return x;
    } else {
        return x * power(x, y - 1);
    }
}
