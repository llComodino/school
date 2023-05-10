/*
 * Siete stati promossi a Comiss di sala e dovete gestire le prenotazioni del vostro ristorante
 * Definite un array a due dimensioni 80x80 che sarà la totalità della sala.
 * Definite all'interno di esso un numero di tavoli non tutti della stessa dimensione,
 * Una volta stabiliti il numero di tavoli (quantificare) dovrete orgnanizzare le prenotazioni.
 * Simulate la richiesta da parte dell'utente finchè la sala non è piena per la disponibilità dei tavoli.
 * Per ogni tavolo prenotato dovrete utilizzare le locazioni di memoria che compongono il tavolo incrementandole di uno.
 * Qualora la richiesta dell'utente non sia effettuabile informarlo con un messaggio.
 * Posizionate i tavoli a debita distanza l'uno dall'altro, così da consentire ai ccamerieri di passarci accanto
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 80
#define BIG_TABLE 6
#define SMALL_TABLE 2
#define MID_TABLE 4

int create_tables (double [][SIZE]);
bool assign_tables (double [][SIZE]);

//debug
void print_tables (const double [][SIZE]);

int main (void) {

    srand(time(NULL));
    double tables[SIZE][SIZE] = {0};

    int table_counter = create_tables(tables);
    printf("Tables: %d\n\n", table_counter);
    // print_tables(tables);

    for (int i = 0; i < table_counter && assign_tables(tables); i++);

    return 0;
}

int create_tables (double tables[][SIZE]) {

    int table_counter;;
    for (size_t i = 0; i < SIZE - 1; i += 3) {
        for (size_t j = 0; j < SIZE - SMALL_TABLE - 1; j++) {

            if (j < SIZE - BIG_TABLE) {
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

bool assign_tables (double tables[][SIZE]) {

    bool perfect_fit(double [][SIZE], const double *const);
    bool bigger(double [][SIZE], const double *const);

    // puts("Tables range from 2 to 8 seats");
    double people = 8;
    // puts("How many people are you?");
    // scanf("%le", &people);

    if (perfect_fit(tables, &people)) {
        return true;
    } else if (bigger(tables, &people)) {
        return true;
    }

    puts("We don't have any free table that big!");

    char sel;
    puts("Continue? [y/n]");
    scanf("%s", &sel);
    puts("");

    if (sel == 'y' || sel == 'Y') {
        return true;
    }
    return false;
}

bool perfect_fit(double tables[][SIZE], const double *const people) {

    for (size_t i = 0; i < SIZE - 1; i += 3) {
        for (size_t k = 0; k < SIZE; k++) {
            if (tables[i][k] * 10 == *people * 10) {
                for (size_t j = k; j < k + *people; j++) {
                    tables[i][j] += 0.1;
                    tables[i + i][j] += 0.1;
                }
                return true;
            }
        }
    }
    return false;
}

bool bigger(double tables[][SIZE], const double *const people) {

    for (size_t i = 0; i < SIZE - 1; i += 3) {
        for (size_t k = 0; k < SIZE; k++) {
            if (tables[i][k] * 10 >= *people * 10) {
                for (size_t j = k; j < k + *people; j++) {
                    tables[i][j] += 0.1;
                    tables[i + i][j] += 0.1;
                }
                return true;
            }
        }
    }
    return false;
}

void print_tables (const double tables[][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            printf("%3f", tables[i][j]);
        }
        puts("");
    }
    return;
}
