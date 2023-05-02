// Diego Gila       3Ein
#include <stdio.h>

int multiplo(int x, int y);

int main(void)
{
    int n1, n2;

    printf("Inserire due numeri: ");
    scanf("%d%d", &n1, &n2);

    printf("%d", multiplo(n1, n2));
    return 0;
}

int multiplo(int x, int y)
{
    if ((y % x) == 0)
        return 1;

    else
        return 0;
}