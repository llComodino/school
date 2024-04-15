// Leggere in input 20 numeri compresi tra 10 e 100
// Stampare a schermo il numero in caso non sia gia stato letto
// Utilizzare il vettore più piccolo possibile
#include <stdio.h>

#define SIZE 5

int main(void) {
  int v[SIZE], c = SIZE;
  for (int i = 0; i < SIZE; i++) {
    do {
      printf("> ");
      scanf("%d", &v[i]);
    } while (v[i] > 100 || v[i] < 10);

    for (int k = 0; k < i; k++) {
      if (k == i)
        continue;

      if (v[i] == v[k]) {
        v[k] = 0;
        c--;
        continue;
      }
    }
  }

  int vf[c];
  for (int j = 0, k = 0; j < SIZE; j++)
    if (v[j] != 0) {
      vf[k] = v[j];
      k++;
    }

  printf("Numeri singoli: ");
  for (int i = 0; i < c; i++)
    printf("%4d", vf[i]);

  return 0;
}
