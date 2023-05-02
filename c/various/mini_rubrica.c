#include <stdio.h>

// Dimesioni
#define SIZE 3
#define BUFFER 64

// Funzione per stampare la rubrica
void printList(const char[SIZE][BUFFER], const char[SIZE][BUFFER], const char[SIZE][BUFFER], const long long int[SIZE][1]);

int main(void)
{
    // Informazioni sul contatto
    char name[SIZE][BUFFER];
    char surname[SIZE][BUFFER];
    char email[SIZE][BUFFER];

    // Impossibile prendere nueri fissi
    long long int phone[SIZE][1];

    // Ciclo per registrare i contatti
    for (int i = 0; i < SIZE; i++)
    {
        printf("Contact %d\n", i + 1);

        printf("Insert name and surname: ");
        scanf("%s%s", name[i], surname[i]);

        printf("Insert phone number: ");
        scanf("%lld", &phone[i][0]);

        printf("Insert email: ");
        scanf("%s", email[i]);

        system("cls");
    }

    // Stampo la rubrica
    printList(name, surname, email, phone);

    return 0;
}

void printList(const char name[SIZE][BUFFER], const char surname[SIZE][BUFFER], const char email[SIZE][BUFFER], const long long int phone[SIZE][1])
{
    printf("\n\n");

    // Stampo le informazioni per ogni contatto
    for(int i = 0; i < SIZE; i++)
    {
        printf("Contact %d\n", i + 1);
        printf("Name: %s\n", name[i]);
        printf("Surname: %s\n", surname[i]);
        printf("Email: %s\n", email[i]);
        printf("Phone: %lld\n", phone[i][0]);
        printf("\n  ----------------------\n\n");
    }
}