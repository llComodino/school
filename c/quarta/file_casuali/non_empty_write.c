#include <stdio.h>
#include <string.h>

#define SIZE 100
#define BUF 16

typedef struct {
    unsigned int id;
    char name[BUF];
    char surname[BUF];
    double balance;
} ClientData;

void write_to_file (FILE *file, ClientData *client) {
 
    strcpy(client->name, "John");
    strcpy(client->surname, "Doe");
    client->balance = 100.0;

    for (size_t i = 1; i <= SIZE; i++) {
        client->id = (int)i;
    
        fseek(file, (client->id - 1) * sizeof(ClientData), SEEK_SET);
        fwrite(client, sizeof(ClientData), 1, file);
    }
    return;
}

int main (void) {

    FILE *file;

    if ((file = fopen("accounts.dat", "rb+")) == NULL) {
        printf("Error opening file\n");
    } else {

        ClientData client = {0, "", "", 0.0};

        write_to_file(file, &client);

        fclose(file);
    }

    return 0;
}
