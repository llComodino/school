// Diego Gila       3 Ein
//
// In un azienda si vendono 5 tipi di prodotti differenti
// Prodotto:        Prezzo:
// 1                2.98
// 2                4.50
// 3                9.98
// 4                4.49
// 5                6.87
// Scrivere un programma che prenda una serie di coppie di numeri
// Primo numero: numero prodotto
// Secondo numero: quantita' prodotto
// Attraverso lo switch determinare la quantita' e il prezzo dei prodotti venduti in una settimana
// Hint: Utilizzare un ciclo per la settimana ed uno per il giorno corrente
#include <stdio.h>
#include <comodino.h>                                   // Libreria personalizzata contenente varie funzioni matematiche e/o comode per i programmi scolastici

int main()
{
    // Variabili
    int np = 1, qp;                                     // Numero prodotto, quantita' prodotto
    int q[5] = {0, 0, 0, 0, 0};                         // Un array per raccogliere le quantita' totali per singolo prodotto
    float tot[6] = {0, 0, 0, 0, 0, 0};                  // Un array per raccogliere il ricavo di ogni singolo prodotto
    float p[5] = {2.98, 4.50, 9.98, 4.49, 6.87};        // Un array contenente i prezzi di ogni articolo

    printf("Prodotto:\tPrezzo:\n1\t\t%.2f\n2\t\t%.2f\n3\t\t%.2f\n4\t\t%.2f\n5\t\t%.2f\n\n", p[0], p[1], p[2], p[3], p[4]);
    for (int i = 1; i <= 7; i++)                        // Ciclo che itera 7 volte (1 settimana)
    {
        while (np != 0 && np != -1)                     // Condizione np != 0 per permettere di uscire dal while, np != -1 per terminare il programma
        {
            if (i == 7)                                 // In caso siamo all'ultimo giorno il prompt cambia
            {
                printf("\nGiorno %d\n", i);
                printf("Inserire il numero del prodotto (0 per visualizzare il totale)[-1 per terminare]: ");
                scanf("%d", &np);                       // Input np
            }
            else if (i != 7)                            // Per tutti gli altri giorni resta invariato
            {
                printf("\nGiorno %d\n", i);
                printf("Inserire il numero del prodotto (0 per passare al giorno successivo)[-1 per terminare]: ");
                scanf("%d", &np);                       // Input np
            }

            if (np != 0 && np != -1)                    // Avendo precedentemente preso np stabilisco un'ulteriore condizione per determinare se l'utente ha scelto di cambiare giorno o uscire dal programma
            {
                printf("Inserire la quantita' di prodotto venduta: ");
                scanf("%d", &qp);                       // Se l'utente ha inserito un valore di np divero da 0 e -1 gli chiedo di inserire la quantita' di prodotto venduta
            }
            switch (np)                                 // Switch con argomento np per analizzare i casi per ogni prodotto
            {
            case 1:
                q[0] += qp;                             // Aumento la quantita' di vendite del singolo prodotto
                tot[0] += qp * p[0];                    // Aumento il ricavo del singolo prodotto
                tot[5] += qp * p[4];                    // Aumento il prezzo totale
                break;

            case 2:
                q[1] += qp;
                tot[1] += qp * p[1];
                tot[5] += qp * p[4];
                break;

            case 3:
                q[2] += qp;
                tot[2] += qp * p[2];
                tot[5] += qp * p[4];
                break;

            case 4:
                q[3] += qp;
                tot[3] += qp * p[3];
                tot[5] += qp * p[4];
                break;

            case 5:
                q[4] += qp;
                tot[4] += qp * p[4];
                tot[5] += qp * p[4];
                break;

            case -1:                                                        // In caso l'utente abbia scelto -1 devo impedire al ciclo for di iterare ulteriormente, vado quindi a modificare la variabile contatore
                i = 8;
                break;

            case 0:                                                         // In caso l'utente voglia cambiare giorno non succede nulla
                break;
            
            default:
                printf("%d non corrisponde a nessun prodotto\n\n", np);     // Un caso default per ogni valore inaspettato
                break;
            }
        }
        if (np != -1)                                                       // In caso l'utente abbia scelto di passare al giorno successivo devo cambiare il valore di np da 0 a uno diverso da 0 e -1 per permettere al ciclo while di iterare
            np++;                                                           // Post-incremento np
    }
    if (np != -1)
    {
        printf("\n\n%s%13s%11s\n", "Prodotto", "Frequenza", "Ricavo");

        for (int i = 0; i <= 4; i++)                                                           // Se l'utente ha scelto -1 non necessita di leggere la tabella di risultati, controllo con un if la scelta
            printf("%d%15.2f%14.2f\n", i, avg(7, q[i]), tot[i]);

        printf("\nTotale: %.2f\n\n", tot[5]);
    }
        // Nel printf precedente e' presente la funzione "avg(int x, float y)", situata nella libreria comodino.h (scritta dal sottoscritto)
        // Grazie a questa calcolo la frequenza giornaliera di vendite per il singolo prodotto un una settimana
}


