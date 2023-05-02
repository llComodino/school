// Scrivere una calcolatrice con le funzioni

#include <stdio.h>
#include <math.h>

float addizione(float x, float y);
float sottrazione(float x, float y);
float moltiplicazione(float x, float y);
float divisione(float x, float y);
int resto(int x, int y);

int main()
{
    int choice = 1, r1, r2, e;
    float n1, n2;
    double d1;

    while (choice != 0)
    {
        printf("1. Addizione\n2. Sottrazione\n3. Moltiplicazione\n4. Divisione\n5. Resto\n6. Potenza\n7. Radice Quadrata\n\n0. Chiudere il programma\n\nSeleiona l'opzione: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Inserisci i due numeri: ");
            scanf("%f%f", &n1, &n2);

            printf("Il totale vale: %.2f\n\n", addizione(n1, n2));
            break;

        case 2:
            printf("Inserisci i due numeri: ");
            scanf("%f%f", &n1, &n2);

            printf("Il totale vale: %.2f\n\n", sottrazione(n1, n2));
            break;

        case 3:
            printf("Inserisci i due numeri: ");
            scanf("%f%f", &n1, &n2);

            printf("Il totale vale: %.2f\n\n", moltiplicazione(n1, n2));
            break;

        case 4:
            printf("Inserisci i due numeri: ");
            scanf("%f%f", &n1, &n2);

            printf("Il totale vale: %.2f\n\n", divisione(n1, n2));
            break;

        case 5:
            printf("Inserisci i due numeri: ");
            scanf("%d%d", &n1, &n2);

            printf("Il totale vale: %d\n\n", resto(r1, r2));
            break;

        case 6:
            printf("Inserisci la base e l'esponente: ");
            scanf("%lf%d", &d1, &n2);

            printf("Il totale vale: %.2f\n\n", pow(d1, e));
            break;

        case 7:
            printf("Inserisci il numero: ");
            scanf("%lf", &d1);

            printf("Il totale vale: %.2f\n\n", sqrt(d1));
            break;

        case 0:
            printf("Grazie dell'utilizzo!\n");
            break;
        
        default:
            printf("\n%d non corrisponde a nessuna funzione!\nInserisci una funzione valida\n\n", choice);
            break;
        }
    }
}

float addizione(float x, float y)
{
    return x + y;    
}

float sottrazione(float x, float y)
{
    return x - y;
}

float moltiplicazione(float x, float y)
{
    return x * y;
}

float divisione(float x, float y)
{
    return x / y;
}

int resto(int x, int y)
{
    return x % y;
}