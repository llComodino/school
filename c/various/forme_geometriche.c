// Scrivere un programma che preso in input il lato di un quadrato lo disegni utilizzando soltanto asterischi
// Ilvostro programma dovra' funzionare con tutti i quadrati di lato compreso tra 1 e 20
#include <stdio.h>

int main()
{
    int lato;

    do {   
        printf("Inserire il lato del quadrato [1-20]: ");
        scanf("%d", &lato);
    } while (lato < 1 || lato > 20);

    for (int i = 0; i < lato; i++)
    {
        for (int i = 0; i < lato; i++)
            printf("* ");
        printf("\n");
    }
    return 0;
}