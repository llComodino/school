// Diego Gila       3Ein
#include <stdio.h>

int main()
{
    int saldo, c, lim;
    for (int i = 0; i < 3; i++)
    {
        printf("Inserire il numero del conto cliente: ");
        scanf("%d", &c);

        printf("Inserire il credito massimo: ");
        scanf("%d", &lim);

        printf("Inserire il saldo corrente: ");
        scanf("%d", &saldo);
        
        printf("\nIl nuovo limite di credito vale: %d\n", lim / 2);

        if (saldo <= lim / 2)
            printf("Il saldo corrente rientra nel nuovo limite\n\n");

        else
            printf("Il saldo corrente non rientra nel nuovo limite\n\n");
    }
    return 0;
}