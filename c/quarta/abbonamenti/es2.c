#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RECORD 7
#define BUFFER 32

int main(void) {

  int id, days;
  char *name = (char *)malloc(sizeof(char) * BUFFER);
  double balance;

  FILE *file;

  if ((file = fopen("record.txt", "r")) == NULL) {
    puts("Error, could not open file");
  } else {

    while (true) {

      puts("1. < 100\n2. > 100\n3. Negative Balance\n4. Terminate\n");
      int sel;
      do {
        scanf("%d", &sel);
      } while (sel < 0 || sel > 4);

      if (sel == 4) {
        break;
      }

      printf("%-10s%-10s%-10s%-10s\n", "ID:", "Name:", "Days:", "Balance:");

      switch (sel) {

      case 1:
        while (fscanf(file, "%d%s%d%lf", &id, name, &days, &balance) != EOF) {

          days < 100
              ? printf("%-10d%-10s%-10d%-10.2f0\n", id, name, days, balance)
              : printf("");
        }
        break;

      case 2:
        while (fscanf(file, "%d%s%d%lf", &id, name, &days, &balance) != EOF) {

          days > 100
              ? printf("%-10d%-10s%-10d%-10.2f0\n", id, name, days, balance)
              : printf("");
        }
        break;

      case 3:
        while (fscanf(file, "%d%s%d%lf", &id, name, &days, &balance) != EOF) {

          balance < 0
              ? printf("%-10d%-10s%-10d%-10.2f0\n", id, name, days, balance)
              : printf("");
        }
        break;

      defaut:
        puts("Unhandled exception");
        break;
      }
      rewind(file);
    }
  }

  fclose(file);
  free(name);

  return 0;
}

