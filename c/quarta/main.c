// Vi hanno incaricato di effettuare 5 consegne
// Ogni pacco ha il suo numero di spedizione, che andra' inserito manualmente
// Scrivere un programma che crei una lista di 5 persone con i seguenti dati:
// - Nome e cognome
// - Indirizzo
// - Numero di telefono
// - Indirizzo email
// Terminata la lista trovate il modo per associare ad ogni cliente il proprio pacco

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ORDERS 5
#define PATH 16
#define BUFFER 32
#define CLIENT_ARGUMENTS 6
#define ORDER_ARGUMENTS 2

typedef struct {
    char *name;
    char *surname;
    char *address;
    char *phone;
    char *mail_address;
    int order_id;
} Client;

typedef struct {
    int order_id;
    char *address;
} Order;

void initialize_clients (Client *const);
void assign_orders (Client *const, Order *const);
void send_orders (Client *const, Order *const);
void free_pointers (Client *const, Order *const);

int main (void) {
    
    Client *clients = malloc(ORDERS * sizeof(Client));

    Order *orders = malloc(ORDERS * sizeof(Order));

    initialize_clients(clients);

    assign_orders(clients, orders);

    send_orders(clients, orders);

    free_pointers(clients, orders);

    return 0;
}

void initialize_clients (Client *const client) {

    char *path[ORDERS] = {
        "clients/client1",
        "clients/client2",
        "clients/client3",
        "clients/client4",
        "clients/client5"
    };

    for (size_t i = 0; i < ORDERS; i++) {

        FILE *file; 

        if ((file = fopen(path[i], "r")) == NULL) {
            puts("Error opening file");
        }

        client[i].name = malloc(sizeof(char) * BUFFER);
        client[i].surname = malloc(sizeof(char) * BUFFER);
        client[i].address = malloc(sizeof(char) * BUFFER);
        client[i].phone = malloc(sizeof(char) * BUFFER);
        client[i].mail_address = malloc(sizeof(char) * BUFFER);

        fscanf(file, "%s", client[i].name);
        fscanf(file, "%s", client[i].surname);
        fscanf(file, "%s", client[i].address);
        fscanf(file, "%s", client[i].phone);
        fscanf(file, "%s", client[i].mail_address);
        fscanf(file, "%d", &client[i].order_id);

        fclose(file);
    }
    return;
}

void assign_orders (Client *const clients, Order *const orders) {
    
    for (size_t j = 0; j < ORDERS; j++) {
        orders[j].order_id = 0;
    }

    for (size_t j = 0; j < ORDERS; j++) {
        srand(time(NULL));
        int i;

        do {
            i = rand() % 5;
        } while (orders[i].order_id != 0);

        orders[i].order_id = clients[j].order_id;
        
        orders[i].address = malloc(sizeof(char) * BUFFER);
        strcpy(orders[i].address, clients[j].address);
    }

    return;
}

void send_orders (Client *const clients, Order *const orders) {
    
    srand(time(NULL));

    size_t j;
    for (size_t i = 0; i < ORDERS; i++) {
        do {
            j = rand() % 5;
        } while (orders[j].order_id != clients[i].order_id);

        if (strcmp(orders[j].address, clients[i].address) == 0) {

            printf("\nSendind order: %d to %s %s at %s\nSending an email at: %s\nSending an sms at: %s\n\n", orders[j].order_id, clients[i].surname, clients[i].name, clients[i].address, clients[i].mail_address, clients[i].phone);
        } else {
            printf("\nError, addresses not matching:\n\nOrder id: %d\nReceiver id: %d\n\nOrder address: %s\nReceiver address: %s\n\n", orders[j].order_id, clients[i].order_id, orders[j].address, clients[i].address);
        }     
    }
    return;
}

void free_pointers (Client *const client, Order *const order) {
    
    for (size_t i = 0; i < ORDERS; i++) {
        free(client[i].name);
        free(client[i].surname);
        free(client[i].address);
        free(client[i].phone);
        free(client[i].mail_address);

        free(order[i].address);
    }

    free(client);
    free(order);

    return;
}
