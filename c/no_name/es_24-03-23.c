// Utilizzando quattro funzioni ognuna per le quattro operazioni elementari calcolare e stampare a schermo i risultati di tali operazioni attraverso l'uso dei puntatori
#include <stdio.h>

void sum(double, double, double *ptot);
void dif(double, double, double *ptot);
void mol(double, double, double *ptot);
void div(double, double, double *ptot);

int main(void)
{
    double num1, num2, tot;

    puts("Inser number: ");
    scanf("%lf", &num1);

    puts("Inser number: ");
    scanf("%lf", &num2);

    sum(num1, num2, &tot);
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, tot);
    
    dif(num1, num2, &tot);
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, tot);
    
    mol(num1, num2, &tot);
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, tot);
    
    div(num1, num2, &tot);
    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, tot);

    return 0;
}

void sum(double x, double y, double *ptot)
{
    *ptot = x + y;
    return;
}

void dif(double x, double y, double *ptot)
{
    *ptot = x - y;
    return;
}

void mol(double x, double y, double *ptot)
{
    *ptot = x * y;
    return;
}

void div(double x, double y, double *ptot)
{
    *ptot = x / y;
    return;
}
