#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER 32
#define SIZE 10

typedef struct Node {
    char *name;
    int number;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    unsigned int size;
} List;

bool _is_empty(List *list);
void init(List **list);
void print_list(Node *head);
void append_node(List *list);

int main (void) {

    List *list = NULL;

    init(&list);

    for (size_t i = 0; i < SIZE; i++) {
        append_node(list);
    }

    _is_empty(list) ? puts("List is empty!") : print_list(list->head);

    while (list->head != NULL) {
        list->tail = list->head->next;
        free(list->head->name);
        free(list->head);
        list->head = list->tail;
    }

    return 0;
}

bool _is_empty(List *list) {
    return list->head == NULL;
}

void init(List **list) {

    if ( ((*list) = (List*)malloc(sizeof(List))) == NULL) {
        fprintf(stderr, "Error allocating memory for list");
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

void print_list(Node *head) {

    if (head != NULL) {
        printf("%s\t%d\n", head->name, head->number);
        print_list(head->next);
    }

    return;
}

void append_node(List *list) {

    if (_is_empty(list)) {

        if ( (list->head = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Error allocating head");
            exit(1);
        }

        list->head->name = NULL;
        list->head->next = NULL;
        list->head->prev = NULL;

        if ( (list->tail = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Error allocating tail");
        }

        list->tail->name = NULL;
        list->tail->next = NULL;
        list->tail->prev = NULL;

        puts("Creating head");

        list->head->name = (char*) malloc(sizeof(char) * BUFFER);

        strcpy(list->head->name, "comodino");
        list->head->number = 6;
        
        list->tail->prev = list->head;
        
    } else {

        puts("Creating links");

        if ( (list->tail->prev->next = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Error allocating memory to appended node");
        }

        list->tail->prev->next->name = (char*) malloc(sizeof(char) * BUFFER);

        strcpy(list->tail->prev->next->name, "Como");
        list->tail->prev->next->number = 0;

        list->tail->prev = list->tail->prev->next;
    }
 
    return;
}
