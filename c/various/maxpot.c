// Diego Gila       3Ein
#include <math.h>
#include <stdio.h>

int main(void) {
  int y;

  do {
    printf("Inserisci un intero positivo: ");
    scanf("%d", &y);
  } while (y < 0);

  int x;
  for (x = 0; x * x <= y; x++)
    if (x * x == y)
      break;

  printf("Il numero reale maggiore che rispetta la condizione X^X <= Y: %d", x);
  return 0;
}

