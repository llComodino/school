// Utilizzando le funzioni implementare un programma che stampi a schermo un messaggio di benvenuto
// Acquisisca da standard input 2 numeri da tastiera successivamente li stampi a schermo
// Tutto va eseguito tramite funzioni
#include <stdio.h>
#include <stdlib.h>

void benvenuto()
{
    printf("Benvenuto!\n");
}

void print(int x, int y)
{
    printf("\nNumero 1: %d\nNumero 2: %d", x, y);
}

void getin()
{
    int n1, n2;

    printf("Inserisci 2 nuemri: ");
    scanf("%d%d", &n1, &n2);

    print(n1, n2);
}

int main()
{
    benvenuto();
    getin();
}
