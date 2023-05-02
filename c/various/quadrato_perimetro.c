// Scrivere un programma che stampi solo il perimetro di un quadrato
#include <stdio.h>

int main()
{
    int lato;
 
    do {
        printf("Numero di righe: ");
        scanf("%d", &lato);
    } while ( lato < 1 || lato > 20);
 
    for (int i = 0; i < lato; i++)
        printf("* ");

    printf("\n");
 
    for (int i = 0; i < lato - 2; i++)
    {
        printf("*");
        for (int x = 0; x < lato * 2 - 3; x++)
            printf(" ");
    printf("*\n");
    }
 
    for (int i = 0; i < lato; i++)
        printf("* ");
    
    printf("\n");

    return 0;
}