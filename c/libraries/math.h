// Diego Gila       3Ein
#include <stdio.h>
#include <math.h>

int main(void)
{
    int n;
    printf("Quanti numeri si desidera inserire: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Inserisci un numero: ");
        scanf("%d", &x);

        printf("Negativo: %d\nQuadrato: %.2lf\n", x * -1, pow(x, 2));

        int e;
        printf("Inserire l'esponente desiderato: ");
        scanf("%d", &e);

        printf("Potenza ^%d: %.2lf\n\n", e, pow(x, e));
    }
    return 0;
}
