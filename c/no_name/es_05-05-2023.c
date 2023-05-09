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

#define SIZE 80
#define BIG_TABLE 6
#define SMALL_TABLE 2
#define MID_TABLE 4

void create_tables (int [][SIZE]);
void print_tables (const int [][SIZE]);

int main (void) {

    srand(time(NULL));
    int tables[SIZE][SIZE] = {0};

    create_tables(tables);
    print_tables(tables);

    return 0;
}

void create_tables (int tables[][SIZE]) {

    for (size_t i = 0; i < SIZE - 1; i += 3) {
        for (size_t j = 0; j < SIZE - SMALL_TABLE - 1; j++) {

            printf("\n%4ld%4ld\n", i, j);
            if (j < SIZE - BIG_TABLE) {
                if (rand() % 2 == 0) {
                    puts("Creating Big Table");
                    for (size_t k = j; k < j + BIG_TABLE; k++) {
                        tables[i][k] = BIG_TABLE * 2;
                        tables[i + 1][k] = BIG_TABLE * 2;
                    }
                    j += BIG_TABLE + 1;
                }
            }

            if (j < SIZE - MID_TABLE) {
                if (rand() % 2 == 1) {
                    puts("Creating Mid Table");
                    for (size_t k = j; k < j + MID_TABLE; k++) {
                        tables[i][k] = MID_TABLE * 2;
                        tables[i + 1][k] = MID_TABLE * 2;
                    }
                    j += MID_TABLE + 1;
                }
            }

            if (j < SIZE - SMALL_TABLE) {
                if (rand() % 2 == 0) {
                    puts("Creating Small Table");
                    for (size_t k = j; k < j + SMALL_TABLE; k++) {
                        tables[i][k] = SMALL_TABLE * 2;
                        tables[i + 1][k] = SMALL_TABLE * 2;
                    }
                    j += SMALL_TABLE + 1;
                }
            }
        }
    }
    return;
}

void print_tables (const int tables[][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            printf("%3d", tables[i][j]);
        }
        puts("");
    }
    return;
}
