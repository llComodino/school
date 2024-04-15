#include <malloc.h>
#include <stdio.h>

#define BUF 16
#define RECORDS 100

typedef struct {
  unsigned int ID;
  char name[BUF];
  char surname[BUF];
  double balance;
} ClientData;

void read_file(FILE *const file);

int main(void) {

  FILE *file = fopen("accounts.dat", "rb+");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  read_file(file);

  fclose(file);

  return 0;
}

void read_file(FILE *const file) {

  ClientData client = {0,
                       //(char *) (malloc(sizeof(char) * BUFFER)),
                       //(char *) (malloc(sizeof(char) * BUFFER)),
                       0.0};

  for (size_t i = 0; i < RECORDS; i++) {
    fread(&client, sizeof(ClientData), 1, file);
    printf(
        "ID : %-5u\nName : %-16s\nSurname : %-16s\nBalance : %-8.2f\n\n---\n\n",
        client.ID, client.name, client.surname, client.balance);
  }

  // free(client.name);
  // free(client.surname);

  return;
}

