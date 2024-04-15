// Diego Gila           3 Ein
//
// Scrivere un programma che prenda in input 5 interi
// Il programma dovra' visualizzare un istogramma e per ogni numero inserito
// dovra' mostrare lo stesso numero di asterischi
#include <comodino.h>
#include <stdio.h>
#include <stdlib.h>

void ist(int n);

int main() {
  int n[5];
  printf("Inserisci 5 numeri: ");
  scanf("%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4]);

  ist(n[0]);
  ist(n[1]);
  ist(n[2]);
  ist(n[3]);
  ist(n[4]);
}

void ist(int n) {
  for (int i = n; i > 0; i--)
    printf("+");
  printf("\n");
}
