#include <stdio.h>
#include <stdlib.h>

#define NAME_BUFFER 16
#define RECORDS 100

typedef struct {
    unsigned int ID;
    char *name;
    char *surname;
    double balance;
} ClientData;

void write_to_file (FILE *file, ClientData *const client);

int main (void) {

    FILE *file;

    if ((file = fopen("accounts.dat", "wb")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Initializes file with blank records
    ClientData client = {0, "", "", 0.0};
    write_to_file(file, &client);

    fclose(file);

    return EXIT_SUCCESS;
}

void write_to_file (FILE *file, ClientData *const client) {
 
    client->name = malloc(NAME_BUFFER * sizeof(char));
    client->surname = malloc(NAME_BUFFER * sizeof(char));
    client->name = "John";
    client->surname = "Doe";
    client->balance = 0.0;
    
    for (size_t i = 0; i < RECORDS; i++) {
        client->ID = i;
        fwrite(client, sizeof(ClientData), 1, file);
    }

    return;
}
