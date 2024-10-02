#include <stdio.h>
#include <stdlib.h>

#define BUFFER 32

int main(void) {

  FILE *file;

  if ((file = fopen("file_sequenziale.txt", "r")) == NULL) {

    puts("File not found!");
    exit(2);

  } else {

    unsigned int x;
    puts("1. Zero Balance\n2. Credit Balance\n3. Debit Balance\n4. Terminate "
         "Execution");
    do {
      scanf("%d", &x);
    } while (x < 1 || x > 4);

    while (x != 4) {

      unsigned int account;
      double balance;
      char *name = malloc(sizeof(char) * BUFFER);

      fscanf(file, "%d%s%lf", &account, name, &balance);

      switch (x) {
      case 1:
        puts("\nZero Balance:");

        while (!feof(file)) {
          if (balance == 0) {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
          }
          fscanf(file, "%d%s%lf", &account, name, &balance);
        }
        break;

      case 2:
        puts("\nCredit Balance:");

        while (!feof(file)) {
          if (balance > 0) {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
          }
          fscanf(file, "%d%s%lf", &account, name, &balance);
        }
        break;

      case 3:
        puts("\nDebit Balance:");

        while (!feof(file)) {
          if (balance < 0) {
            printf("%-10d%-13s%7.2f\n", account, name, balance);
          }
          fscanf(file, "%d%s%lf", &account, name, &balance);
        }
        break;

      case 4:
        puts("Program is being terminated ...");
        break;

      default:
        puts("Error, out of bounds");
        break;
      }

      rewind(file);
      free(name);
      puts("\nWhat to do next?");
      scanf("%d", &x);
    }
  }
  fclose(file);
  return 0;
}

