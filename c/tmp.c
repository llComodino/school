#include <stdio.h>

int main (void) {
    FILE *file = fopen("clients.txt", "r");

    printf("Eneter request:\n1. List accounts with zero balance\n2. List accounts with credits balances\n3. List accounts with debit balances\n4. End\n> ");

    unsigned int request;
    scanf("%u", &request);


}
