// Scrivere un programma in C che dichiari un vettore di dimensione 20
// Il vettore dovra' essere riempito casualmente
// Successivamente bisognera' mostrare a schermo un messaggio che chieda
// l'inserimento di un numero x Trovare x all'interno del vettore se esiste
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int v[20];
  int x;
  int i;

  for (i = 0; i < 20; i++)
    v[i] = 1 + rand() % 20;

  bool found = false;
  do {
    printf("> ");
    scanf("%d", &x);

    for (i = 0; i < 20; i++)
      if (x == v[i]) {
        found = true;
        printf("\nTrovata corrispondenza per %d in posizione %d", x, i);
      }
  } while (found == false);

  return 0;
}
