/*
 * Creare un programma che simuli la coda di un negozio.
 * I clienti vengono inseriti in una coda e serviti in ordine di arrivo.
 * Il programma deve permettere di:
 * - Inserire un cliente in coda
 * - Visualizzare la lunghezza della coda
 * - Servire un cliente
 * - Rimuovere un cliente dalla coda (dopo averlo servito)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define BUF 32

typedef struct Node {
    char *name;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

void init(Queue *queue);
void new_customer(Queue *queue, char *name);
void attend_customer(Queue *queue);
int length(Queue *queue);
void print(Queue *queue);
void clear(Queue *queue);
int action(void);

int main (void) {

    Queue *queue = NULL;

    if ( (queue = (Queue *)malloc(sizeof(Queue))) == NULL ) {
        fprintf(stderr, "Error allocating memory for queue (init)\n");
        return 1;
    }

    init(queue);

    int choice = 0;

    do {
        
        choice = action();

        switch (choice) {
            case 1:
                char *name = NULL;

                if ( (name = (char *) malloc(sizeof(char) * BUF)) == NULL ) {
                    fprintf(stderr, "Error allocating memory (name)\n");
                    return 1;
                }

                printf("Inserisci il nome del cliente: ");
 
                do {
                    fgets(name, BUF, stdin);
                } while (strlen(name) < 1);

                if (fgets(name, BUF, stdin) == NULL) {
                    fprintf(stderr, "Error reading name\n");
                    return 1;
                }

                new_customer(queue, name);
            break;

            case 2:
                printf("Lunghezza coda: %d\n", length(queue));
                break;
            
            case 3:
                attend_customer(queue);
                break;
            
            case 4:
                print(queue);
                break;
            
            case 5:
                clear(queue);
                break;
            
            case 0:
                printf("Uscita dal programma\n");
                break;
            
            default:
                printf("Scelta non valida\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

void init(Queue *queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void new_customer(Queue *queue, char *name) {
    
    if (queue->size == MAX) {
        printf("Coda piena\n");
        return;
    }

    Node *new = NULL;

    if ( (new = (Node *)malloc(sizeof(Node))) == NULL ) {
        fprintf(stderr, "Error allocating memory for new customer\n");
        return;
    }

    if ( (new->name = (char *)malloc(sizeof(char) * BUF)) == NULL ) {
        fprintf(stderr, "Error allocating memory for new customer name\n");
        return;
    }

    strcpy(new->name, name);
    new->next = NULL;

    if (queue->size == 0) {
        queue->head = new;
        queue->tail = new;
    } else {
        queue->tail->next = new;
        queue->tail = new;
    }

    queue->size++;
}

void attend_customer(Queue *queue) {
    if (queue->size == 0) {
        printf("Nessun cliente in coda\n");
        return;
    }

    Node *temp = queue->head;
    queue->head = queue->head->next;
    free(temp->name);
    free(temp);
    queue->size--;
}

int length(Queue *queue) {
    return queue->size;
}

void print(Queue *queue) {
    
    if (queue->size == 0) {
        printf("Nessun cliente in coda\n");
        return;
    }

    Node *temp = queue->head;

    for (int i = 0; i < queue->size; i++) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

void clear(Queue *queue) {
    if (queue->size == 0) {
        printf("Nessun cliente in coda\n");
        return;
    }

    Node *temp = queue->head;
    Node *next = NULL;

    for (int i = 0; i < queue->size; i++) {
        next = temp->next;
        free(temp->name);
        free(temp);
        temp = next;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

int action(void) {
    int choice = 0;

    printf("1. Inserisci cliente\n");
    printf("2. Lunghezza coda\n");
    printf("3. Servi cliente\n");
    printf("4. Stampa coda\n");
    printf("5. Svuota coda\n");
    printf("0. Esci\n");
    printf("Scelta: ");
    scanf("%d", &choice);

    return choice;
}
