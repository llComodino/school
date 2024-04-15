#include <stdio.h>

void sumPtrs(int, int, int *sum);

int main(void) {
  int x, y, sum;

  puts("Insert x value: ");
  scanf("%d", &x);

  puts("Insert y value: ");
  scanf("%d", &y);

  sumPtrs(x, y, &sum);

  printf("\n%d + %d = %d\n\n", x, y, sum);
}

void sumPtrs(int x, int y, int *sum) { *sum = x + y; }
