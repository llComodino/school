// Scrivere un programma in c che calcoli e visualizzi tutti i prodotti dei
// numeri dispari da 1 a 15
#include <stdio.h>

int main() {
  for (int i = 1; i <= 15;
       i += 2) // Primo ciclo utile per settare il moltiplicatore (rimane fisso
               // durante l'esecuzione del for nestato)
  {
    printf("\nProdotti di %d\n", i);
    for (int x = 1; x <= 15;
         x += 2) // Secondo ciclo utile per settare il moltiplicando
      printf("%d * %d = %d\n", i, x,
             i * x); // Stampa a schermo dei risultati con relativa espressione
  }
}
// Termine programma