// Diego Gila       3Ein
#include <stdio.h>
#include <math.h>

float min(float n1, float n2, float n3);

int main(void)
{
    float f1, f2, f3;
    printf("Inserisci 3 numeri in virgolamobile: ");
    scanf("%f%f%f", &f1, &f2, &f3);

    printf("Minore: %f\n", min(f1, f2, f3));
}

float min(float n1, float n2, float n3)
{
    float min = n1;

    if (min > n2)
        min = n2;

    if (min > n3)
        min = n3;

    return min;
}
