/*
 * Siete stati promossi a Comiss di sala e dovete gestire le prenotazioni del
 * vostro ristorante Definite un array a due dimensioni 80x80 che sarà la
 * totalità della sala. Definite all'interno di esso un numero di tavoli non
 * tutti della stessa dimensione, Una volta stabiliti il numero di tavoli
 * (quantificare) dovrete orgnanizzare le prenotazioni. Simulate la richiesta da
 * parte dell'utente finchè la sala non è piena per la disponibilità dei tavoli.
 * Per ogni tavolo prenotato dovrete utilizzare le locazioni di memoria che
 * compongono il tavolo incrementandole di uno. Qualora la richiesta dell'utente
 * non sia effettuabile informarlo con un messaggio. Posizionate i tavoli a
 * debita distanza l'uno dall'altro, così da consentire ai ccamerieri di
 * passarci accanto
 * */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15
#define BIG_TABLE 4
#define SMALL_TABLE 2
#define MID_TABLE 3

int create_tables(int[][SIZE]);
bool assign_tables(int[][SIZE]);

// debug
void print_tables(const int[][SIZE]);

int main(void) {

  srand(time(NULL));
  int tables[SIZE][SIZE] = {0};

  int table_counter = create_tables(tables);
  printf("Tables: %d\n\n", table_counter);
  print_tables(tables);

  while (assign_tables(tables))
    ;

  return 0;
}

int create_tables(int tables[][SIZE]) {

  int table_counter;
  for (size_t i = 0; i < SIZE - 1; i += 3) {
    for (size_t j = 0; j < SIZE - SMALL_TABLE - 1; j++) {

      if (j < SIZE - BIG_TABLE) {
        if (rand() % 2 == 0) {
          table_counter++;
          for (size_t k = j; k < j + BIG_TABLE; k++) {
            tables[i][k] = BIG_TABLE * 2;
            tables[i + 1][k] = BIG_TABLE * 2;
          }
          j += BIG_TABLE + 1;
        }
      }

      if (j < SIZE - MID_TABLE) {
        if (rand() % 2 == 0) {
          table_counter++;
          for (size_t k = j; k < j + MID_TABLE; k++) {
            tables[i][k] = MID_TABLE * 2;
            tables[i + 1][k] = MID_TABLE * 2;
          }
          j += MID_TABLE + 1;
        }
      }

      if (j < SIZE - SMALL_TABLE) {
        if (rand() % 2 == 0) {
          table_counter++;
          for (size_t k = j; k < j + SMALL_TABLE; k++) {
            tables[i][k] = SMALL_TABLE * 2;
            tables[i + 1][k] = SMALL_TABLE * 2;
          }
          j += SMALL_TABLE + 1;
        }
      }
    }
  }
  return table_counter;
}

bool assign_tables(int tables[][SIZE]) {

  bool perfect_fit(int[][SIZE], const int *const);
  bool bigger(int[][SIZE], const int *const);

  // puts("Tables range from 2 to 8 seats");
  int people;
  // puts("How many people are you?");
  scanf("%d", &people);

  if (perfect_fit(tables, &people)) {
    // print_tables(tables);
    puts("PF");
    return true;
  } else if (bigger(tables, &people)) {
    puts("B");
    return true;
  } else {
    puts("We don't have any free table that big!");

    char sel;
    puts("Continue? [y/n]");

    do {
      scanf("%s", &sel);
    } while (sel != 'y' && sel != 'Y' && sel != 'n' && sel != 'N');
    puts("");

    if (sel == 'y' || sel == 'Y') {
      return true;
    }
  }
  return false;
}

bool perfect_fit(int tables[][SIZE], const int *const people) {

  for (size_t i = 0; i < SIZE - 1; i += 3) {
    for (size_t k = 0; k < SIZE - SMALL_TABLE; k++) {
      if (tables[i][k] == *people) {
        printf("%d\t%d\n", tables[i][k], *people);
        for (size_t j = k; j < k + *people; j++) {
          tables[i][j] *= 10;
          tables[i + 1][j] *= 10;
        }
        return true;
      }
    }
  }
  return false;
}

bool bigger(int tables[][SIZE], const int *const people) {

  for (size_t i = 0; i < SIZE - 1; i += 3) {
    for (size_t k = 0; k < SIZE - SMALL_TABLE; k++) {
      if (tables[i][k] >= *people && tables[i][k] < 10) {
        printf("%d\t%d\n", tables[i][k], *people);
        for (size_t j = k; j < k + *people; j++) {
          tables[i][j] *= 10;
          tables[i + 1][j] *= 10;
        }
        return true;
      }
    }
  }
  return false;
}

void print_tables(const int tables[][SIZE]) {
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
      printf("%2d", tables[i][j]);
    }
    puts("");
  }
  return;
}

