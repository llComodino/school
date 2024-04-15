// Diego Gila       3Ein
#include <stdio.h>

int even(int x);

int main(void) {
  int n;
  printf("Inserire un numero: ");
  scanf("%d", &n);

  printf("%d", even(n));
  return 0;
}

int even(int x) {
  if ((x % 2) == 0)
    return 1;

  else
    return 0;
}
