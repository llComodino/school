// Scrivere un programma per la gestione di una promozione di articoli da vela
// presso un grossista La promozione e' riferita ai guanti che possono essere di
// tre tipi riportati di seguito con i rispettivi prezzi Cotone: $10 Pelle: $25
// Neoprene: $30
// si gestisca il caso in cui un unico cliente che possa fare un numero di
// ordini di acquisto a piacere ognuno dei quali e' riferito ad un solo tipo di
// guanti
// 1. Si richieda all'utente il numero di ordni da inserire
// 2. si calcoli e stampii per ogni tipo di gunto la spesa totale degli ordini
// ad esso associati
#include <stdio.h>

#define SIZE 3
#define BUFFER 32

void print(int[][SIZE], char[][BUFFER]);
void orders(int[][SIZE], int);
void print_total(int[][SIZE], char names[][BUFFER]);

int main(void) {
  char names[SIZE][BUFFER] = {{"Cotton"}, {"Leather"}, {"Neophrene"}};

  int products[SIZE][SIZE] = {{10, 25, 30}, {0}, {0}};

  int order;
  puts("How many orders would you like to place? ");
  scanf("%d", &order);

  puts("`\n\n");

  print(products, names);
  orders(products, order);

  print_total(products, names);
}

void print(int products[][SIZE], char names[][BUFFER]) {
  for (int i = 0; i < SIZE; i++) {
    printf("%d. %10s gloves: %2d$\n", i + 1, names[i], products[0][i]);
  }
  puts("\n\n");
}

void orders(int products[][SIZE], int x) {
  int prd;
  int qnt;

  for (int i = 0; i < x; i++) {
    do {
      puts("What kind of goves would you like to purchase for this order?\n");
      scanf("%d", &prd);
    } while (products[1][prd - 1] != 0);

    puts("\nHow many of them? ");
    scanf("%d", &qnt);

    products[1][prd - 1] = qnt;
    products[2][prd - 1] = products[0][prd - 1] * qnt;
  }
}

void print_total(int products[][SIZE], char names[][BUFFER]) {
  for (int i = 0; i < SIZE; i++) {
    if (products[1][i] != 0) {
      printf("You purchased %d %s gloves for %d $\n", products[1][i], names[i],
             products[2][i]);
    }
  }
}

