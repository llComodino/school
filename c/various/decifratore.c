#include <stdio.h>

int main() {
  int num, c[4];

  printf("Inserire un intero di 4 cifre da crittografare: ");
  scanf("%d", &num);

  for (int i = 0; i < 4; i++) {
    if ((num % 10) >= 7)
      c[i] = ((num % 10) - 7) % 10;

    else
      c[i] = ((num % 10) + 10 - 7) % 10;

    num /= 10;
  }
  printf("\n%d%d%d%d", c[1], c[0], c[3], c[2]);
}