#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct Node {
    unsigned int data;
    Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    Node *current;
} List;

void print_menu(void);
void push(List *list, unsigne int val);
unsigned int pop(List *list);
void add_node(List *list);

int main (void) {

    List *list = NULL;

    if ( (list = (List *) malloc(sizeof(List)) ) == NULL ) {
        fprintf(stderr, "Error allocating memory");
    }

    int choice = 0;
    size_t idx = 0;
    unsigned int val = 0;

    do {
        print_menu();

        do {
            scanf("%d", &choice);
        } while (choice < 0 || choice > 4);

        switch (choice) {

            case 0:
                puts("Goodbye");
                break;

            case 1:
                print_list(list);
                break;

            case 2:
                do {
                    printf("Enter integer value [0 - 1000]: ");
                    scanf("%d", &val);
                } while (val < 0 || val > MAX);

                push(list, &val);
                break;

            case 3:
                printf("Popped %d\n\n", pop(list));
                break;

            case 4:
                do {
                    printf("Enter integer value [0 - 1000]: ");
                    scanf("%d", &val);
                } while (val < 0 || val > MAX);
                break;

            case 5:

                break;
        

    } while (choice != 0);

    return 0;
}

void print_menu(void) {

    puts("What would you like to do?");
    puts("1. Print List");
    puts("2. Push Value");
    puts("3. Pop Value");
    puts("4. Add Value at Position");
    puts("0. Exit");
    printf("Selection: ");

    return;
}

void push(List *list, unsigned int val);
unsigned int pop(List *list);
void add_node(List *list, int *idx);
