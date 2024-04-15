// Diego Gila       3Ein
// Funzioni applicate alla stampa delle figure geometriche
#include <stdio.h>

void perimetro(int lato);
void quadrato(int lato);

int main() {
  int l;
  printf("Inserisci il lato: ");
  scanf("%d", &l);

  printf("\n");

  perimetro(l);

  printf("\n");

  quadrato(l);
}

void perimetro(int lato) {
  for (int i = 0; i < lato; i++)
    printf("* ");

  printf("\n");

  for (int i = 0; i < lato - 2; i++) {
    printf("*");
    for (int x = 0; x < lato * 2 - 3; x++)
      printf(" ");
    printf("*\n");
  }

  for (int i = 0; i < lato; i++)
    printf("* ");

  printf("\n");
}

void quadrato(int lato) {
  for (int i = 0; i < lato; i++) {
    for (int x = 0; x < lato; x++)
      printf("* ");
    printf("\n");
  }
  printf("\n");
}