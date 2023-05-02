// Scrivere un programma che preso in input un numero di 5 cifre lo spezzetti in ogni singola cifra
// Successivamente stampa a schermo le cifre separate da una tabulazione
// Ad esempio 38257 diventa: 3   8   2   5   7
#include <stdio.h>

int main()
{
    int n;
    printf("Inserisci un numero di 5 cifre: ");
    scanf("%d", &n);

    for (int i = 10000; i > 0; i /= 10)
        printf("%d\t", (n / i) % 10);
    
}