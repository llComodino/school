// Scrivere un programma che prenda in input un numero di 5 cifre
// Acquisito il numero dovretescomporlo in ogni singola cifra
// Chiedere all'utente di aggiungere un numero
#include <stdio.h>

int main() {
  int num;

  do {
    printf("Inserire un numero di 5 cifre: ");
    scanf("%d", &num);
  } while (num < 0 || num > 99999);

  int c[5];
  int x = 0;

  printf("\n\n");

  for (int i = 10000; i >= 1; i /= 10) {
    printf("%d\t", (num / i) % 10);
    c[x] = (num / i) % 10;
    x++;
  }

  printf("\n\n");

  for (int i = 0; i < 5; i++) {
    int n;
    printf("Aggiungi un numero a %d: ", c[i]);
    scanf("%d", &n);
    c[i] += n;
  }

  printf("\n\n");

  for (int i = 0; i < 5; i++) {
    printf("%d\t", c[i]);
  }
  printf("\n");
  return 0;
}
