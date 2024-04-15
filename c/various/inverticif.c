// Diego Gila       3Ein
#include <stdio.h>

void invcif(int x);

int main(void) {
  int n;
  printf("Inserire un numero: ");
  scanf("%d", &n);

  invcif(n);
  return 0;
}

void invcif(int x) {
  for (x; x != 0; x /= 10)
    printf("%d\t", x % 10);
}
