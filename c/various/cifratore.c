#include <stdio.h>

int main() {
  int num, c[4];

  printf("Inserire un intero di 4 cifre da crittografare: ");
  scanf("%d", &num);

  c[3] = ((num % 10) + 7) % 10;
  num /= 10;
  c[2] = ((num % 10) + 7) % 10;
  num /= 10;
  c[1] = ((num % 10) + 7) % 10;
  num /= 10;
  c[0] = ((num % 10) + 7) % 10;

  printf("\n%d%d%d%d", c[2], c[3], c[0], c[1]);
}