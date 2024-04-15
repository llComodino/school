#include <stdio.h>

int main(void) {
  int n, d = 0;

  do {
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &n);
  } while (n < 0);

  for (int i = 1; i != n + 1; i++)
    if (n % i == 0) {
      printf("%d e' un divisore di %d\n", i, n);
      d++;
    }

  if (d <= 2)
    printf("\nNumero Primo");

  return 0;
}

