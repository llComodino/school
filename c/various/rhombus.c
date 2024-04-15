// Diego Gila       3Ein
// Scrivere un programma che stampi a schermo un rombo commposto da soli
// asterischi separati da spazi
#include <stdio.h>

int main() {
  int x, n;

  do {
    printf("Inserire la larghezza del rombo [numero dispari tra 1-19]: ");
    scanf("%d", &n);
    printf("\n");
  } while (n < 1 || n > 19 || (n % 2) == 0);

  for (int i = 1; i < n; i += 2) {
    for (x = 1; x <= n - i; x++)
      printf(" ");

    for (int y = x; y <= n; y++)
      printf("* ");

    printf("\n");
  }

  for (int i = n; i >= 1; i -= 2) {
    for (x = 1; x <= n - i; x++)
      printf(" ");

    for (int y = x; y <= n; y++)
      printf("* ");

    printf("\n");
  }
  printf("\n");
  return 0;
}