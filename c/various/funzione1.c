// Scrivere un programma che presi 2 numeri da tastiera calcoli la somma
// Utilizzo delle funzioni obbligatorio
#include <stdio.h>
#include <stdlib.h>

float sum(float x, float y) { return x + y; }

int main() {
  float n1, n2;

  printf("Inserisci due numeri: ");
  scanf("%f%f", &n1, &n2);

  printf("Il totale vale %.2f", sum(n1, n2));
}