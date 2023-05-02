// Scrivere un programma che sommi una sequenza di interi
// Supponete che il primo intero letto con lo scanf indichi il numero dei valori che dovranno essere immessi
// Il programma dovra' leggere soltanto un valore per volta ogni volta che lo scanf verra' eseguito

#include <stdio.h>

int main()
{
    int x, y, tot = 0, i;

    printf("Numero di addendi: ");
    scanf("%d", &x);

    for (i = 0; i < x; i++)
    {
        printf("Inserire un addendo: ");
        scanf("%d", &y);

        tot += y;
    }

    printf("Il totale vale: %d", tot);
    
}