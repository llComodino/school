// Diego Gila       3Ein
// Programma 2
#include <stdio.h>
#include <math.h>

int intround(double i);
double tenround(double d);
double hunround(double c);
double thoround(double m);

int main(void)
{
    double x;
    printf("Insert value of x: ");
    scanf("%lf", &x);

    printf("Integer value: %d\nTenth value: %.1lf\nHundreths value: %.2lf\nThousandths value: %.3lf\n", intround(x), tenround(x), hunround(x), thoround(x));
}

int intround(double i)
{
    return floor(i + .5);
}

double tenround(double d)
{
    return floor(d * 10 + .5) / 10;
}

double hunround(double c)
{
    return floor(c * 100 + .5) / 100;
}

double thoround(double m)
{
    return floor(m * 1000 + .5) / 1000;
}