/* Scrivere un programma in C che crei un file
 * Ogni record dovrà avere le seguenti informazioni
 * - Numero Cliente
 * - Nome CLiente
 * - Numero Giorni di Abbonamento Trascorsi
 * - Saldo attuale dei pagamenti
 * Il file dovrà contenere 7 record
 * Scrivere poi un altro programma che legga e stampi il contento del file
 * precedentemente creato Facendo attenzione a stampare un'intestazione adeguata
 * per tutta la tabella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD 7
#define BUFFER 32

int main(void) {

  FILE *file;

  int id, days;
  double balance;
  char *name = (char *)malloc(sizeof(char) * BUFFER);

  if ((file = fopen("record.txt", "w")) == NULL) {
    puts("Error, could not open file");
  } else {
    for (int i = 0; i < RECORD; i++) {
      printf("Enter ID, name, number of days, balance (separated by spaces): ");
      scanf("%d%s%d%lf", &id, name, &days, &balance);
      fprintf(file, "%d %s %d %.2f\n", id, name, days, balance);
    }
  }

  fclose(file);
  free(name);

  return 0;
}
