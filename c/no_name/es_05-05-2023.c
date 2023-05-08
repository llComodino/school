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

#define SIZE 80

void create_tables (int [][SIZE]);

int main (void) {

    int tables[SIZE][SIZE];

    create_tables(tables);

    return 0;
}

void create_tables (int tables[][SIZE]) {
    for (size_t i = 0; i < SIZE; i++) {

    }
}
