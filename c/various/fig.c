// Diego Gila       3Ein
#include <stdio.h>

int main(void) {
  int n;
  printf("Inserisci il lato: ");
  scanf("%d", &n);

  // Quadrato Pieno
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("* ");
    printf("\n");
  }

  printf("\n\n");

  // Perimetro
  for (int i = 0; i < n; i++)
    printf("* ");

  printf("\n");

  for (int i = 0; i < n - 2; i++) {
    printf("*");
    for (int j = 0; j < n * 2 - 3; j++)
      printf(" ");
    printf("*\n");
  }

  for (int i = 0; i < n; i++)
    printf("* ");

  printf("\n");

  printf("\n\n");

  // Triangolo Iscoscele Rettangolo
  for (int i = 1; i <= n; i++) {
    for (int j = n - i; j != n; j++)
      printf("* ");

    printf("\n");
  }

  printf("\n\n");

  // Quadrato due Carateri
  int j;
  for (int i = 0; i < n; i++) {
    for (j = n - i - 1; j != n; j++)
      printf("* ");

    for (int k = 1; k < n - i; k++)
      printf("+ ");

    printf("\n");
  }
  return 0;
}
