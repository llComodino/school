// Diego Gila       3Ein
#include <stdio.h>

int main(void)
{
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    int y = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = n - i; x != n; x++)
        {
            printf("%d\t", y);
            y++;
        }
        printf("\n");
    }
    return 0;
}
