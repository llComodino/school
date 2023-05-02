// Diego Gila       3Ein
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, anc, pos = 0, neg = 0, par = 0, dis = 0;
    bool cr = true, dc = true;

    printf("Quanti numeri si vogliono inserire: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Inserisci il numero: ");
        scanf("%d", &x);

        if (i == 0)
            anc = x;
        
        else
        {
            if (cr)
            {
                if (x < anc)
                    cr = false;
                if (x > anc)
                    dc = false;
            }

            if (dc)
            {
                if (x < anc)
                    cr = false;
                if (x > anc)
                    dc = false;
            }

            if (x % 2 == 0)
                par++;
            
            if (x % 2 != 0)
                dis++;

            if (x >= 0)
                pos++;

            if (x < 0)
                neg++;
        }
    }
    printf("Numeri positivi: %d\nNumeri negativi: %d\nNumeri pari: %d\nNumeri dispari: %d\n", pos, neg, par, dis);

    if (cr && dc == false)
        printf("Sequenza crescente");

    if (dc && cr == false)
        printf("Sequenza decrescente");

    else
        printf("Sequenza ne crescente ne decrescente");

    return 0;
}
