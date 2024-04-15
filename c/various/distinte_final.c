#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AGENTS 4
#define COLUMNS 4
#define ELEMENTS 5

double rndPrice(void);
double total(const double distinte[][COLUMNS][ELEMENTS], int, int);
void printTable(const double sales[][ELEMENTS]);

int main(void) {
  srand(time(NULL));

  double distinte[AGENTS][COLUMNS][ELEMENTS] = {
      {{rndPrice(), rndPrice(), rndPrice(), rndPrice(), rndPrice()},
       {0},
       {0},
       {0}}, // First column is for prices
      {{rndPrice(), rndPrice(), rndPrice(), rndPrice(), rndPrice()},
       {0},
       {0},
       {0}}, // Other columns are for totals
      {{rndPrice(), rndPrice(), rndPrice(), rndPrice(), rndPrice()},
       {0},
       {0},
       {0}}, // Initialize the totals to 0
      {{rndPrice(), rndPrice(), rndPrice(), rndPrice(), rndPrice()},
       {0},
       {0},
       {0}} // Give the prices of the products
  };

  int np, qnt;

  // Selling random quantities of products
  for (int i = 1; i < COLUMNS; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < ELEMENTS; k++)
        distinte[j][i][k] += distinte[j][0][k] * (double)(rand() % 4);

  // Storing totals in a matrix
  double sales[AGENTS][ELEMENTS];

  // Assign totals to the elements
  for (int i = 0; i < AGENTS; i++)
    for (int k = 0; k < ELEMENTS; k++)
      sales[i][k] = total(distinte, i, k);

  // Print the table
  printf("\n\n");
  printTable(sales);
}

double rndPrice(void) { return rand() % 50; }

double total(const double distinte[][COLUMNS][ELEMENTS], int agnt, int prd) {
  double total = 0;
  for (int i = 1; i < COLUMNS; i++)
    total += distinte[agnt][i][prd];

  return total;
}

void printTable(const double sales[][ELEMENTS]) {
  double tot = 0;
  // Stampa riga 0 (nomi agenti)
  printf("%20s%3d", "Agente", 1);
  for (int i = 1; i < AGENTS; i++)
    printf("%9s%3d", "Agente", i + 1);
  printf("%12s", "Tot");

  // Stampe prodotti e relativi totali
  for (int i = 0; i < 5; i++) {
    printf("\n%8s%3d", "Prodotto", i + 1);
    for (int k = 0; k < AGENTS; k++) {
      printf("%12.2lf", sales[k][i]);
      tot += sales[k][i];
    }
    // Stampa delle vendite totali per prodotto
    printf("%12.2lf", tot);
    tot = 0;
  }
  // Stampa delle vendite totali per agente
  printf("\n%11s", "Tot Agente");
  for (int i = 0; i < AGENTS; i++) {
    for (int k = 0; k < ELEMENTS; k++) {
      tot += sales[i][k];
    }
    printf("%12.2lf", tot);
    tot = 0;
  }
}
