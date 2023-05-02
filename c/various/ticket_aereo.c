// Diego Gila           3Ein
#include <stdio.h>
#include <stdlib.h>

// MUST BE EVEN
#define SIZE 10

// Printing Functions
void printMenu();
void printSeats(const int posti[]);
void printTicket(int n, int class);

// Array Modifying Functions
void buyFirstClass(int posti[]);
void buySecondClass(int posti[]);

int main(void)
{
    int posti[SIZE] = {0};
    int selezione = 0;
    do {
        
        printf("\nBenvenuto!\nCosa desideri fare?\n\n");
    
        do {
            printMenu();
            scanf("%d", &selezione);
        } while (selezione < 0 || selezione > 2);

        if (selezione == 1)
            buyFirstClass(posti);

        if (selezione == 2)
            buySecondClass(posti);

        if (selezione == 0)
            return 0;

    } while (selezione != 0);

    return 0;
}

void printMenu()
{
    printf("1. Biglietto Prima Classe\n");
    printf("2. Biglietto Seconda Classe\n");
    printf("0. Terminare\n\n");
}

void printSeats(const int posti[])
{
    for (int i = 0; i < SIZE; i++)
        {
            if (i % (SIZE / 2) == 0)
                printf("\n");
            printf("%4d", posti[i]);
        }
}

void buyFirstClass(int posti[])
{
    int counter = 0;
    for (int i = 0; i < SIZE / 2; i++, counter++)
        if (posti[i] == 0)
        {
            posti[i]++;
            printTicket(counter, 1);
            break;
        }

    if (counter == SIZE / 2)
    {
        printf("Posti Esauriti!\n\n");

        counter = 0;
        for (int i = SIZE / 2; i < SIZE; i++)
        {
            if (posti[i] == 1)
                counter++;
        }

        if (counter == SIZE / 2)
            printf("Tutto Esaurito!\n\n");

        else
        {
            int choice;
            do {
                printf("Biglietti Seconda Classe Disponibili!\nSi desidera acquistarne uno? [1 - si | 0 - no]  >  ");
                scanf("%d", &choice);
            } while (choice < 0 || choice > 1);

            if (choice == 1)
                buySecondClass(posti);
        }
    }
}

void buySecondClass(int posti[])
{
    int counter = 0;
    for (int i = SIZE / 2; i < SIZE; i++, counter++)
        if (posti[i] == 0)
        {
            posti[i]++;
            printTicket(counter, 2);
            break;
        }
    
    if (counter == SIZE / 2)
    {
        printf("Posti Esauriti!\n\n");

        counter = 0;
        for (int i = 0; i < SIZE / 2; i++)
        {
            if (posti[i] == 1)
                counter++;
        }

        if (counter == SIZE / 2)
            printf("Tutto Esaurito!\n\n");
        else
        {
            int choice;
            do {
                printf("Biglietti Prima Classe Disponibili!\nSi desidera acquistarne uno? [1 - si | 0 - no]  >  ");
                scanf("%d", &choice);
            } while (choice < 0 || choice > 1);

            if (choice == 1)
                buyFirstClass(posti);
        }
    }
}

void printTicket(int n, int class)
{
    printf("\n\n");

    printf("*******************\n");
    printf("* Posto: %d        *\n", n + 1);
    printf("* Classe: %d       *\n", class);
    printf("*******************\n");

    printf("\n\n");
    getch();
}