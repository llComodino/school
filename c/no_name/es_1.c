#include <stdio.h>

void exchange(int *px, int *py);

int main(void) {
  int x, y;

  puts("Insert x value: ");
  scanf("%d", &x);

  puts("Insert y value: ");
  scanf("%d", &y);

  printf("x : %d\ny : %d\n\n", x, y);

  exchange(&x, &y);

  printf("Swapped values:\nx : %d\ny : %d\n\n", x, y);
}

void exchange(int *px, int *py) {
  int hold = *px;
  *px = *py;
  *py = hold;
}

