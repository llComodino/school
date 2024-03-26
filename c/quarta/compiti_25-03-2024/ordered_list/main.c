#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 5

typedef struct Node {
    double val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    double size;
    double sum;
    double avg;
} List;

void __init_list(List **list);
void add_node(List *list);
void populate(List *list, unsigned int len);
void print_list(Node *node);

int main (void) {

    List *list = NULL;
    __init_list(&list);

    populate(list, LEN);

    print_list(list->head);
    
    printf("Sum: %6.2lf\nAvg: %6.2lf\n\n", list->sum, list->avg);

    return 0;
}

void __init_list(List **list) {

    if ( ( (*list) = (List *) malloc(sizeof(List))) == NULL ) {
        fprintf(stderr, "Not enough mem (__init_list)");
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;

    (*list)->size = 0;
    (*list)->sum = 0;
    (*list)->avg = 0;

    return;
}

void add_node(List *list) {

    srand(time(NULL));
    double val = rand() % 101;

    if (list->head == NULL) {

        if ( (list->head = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "not enough mem (add_node)");
        }

        list->head->val = val;
        list->head->next = NULL;
        list->head->prev = NULL;

    } else {

        Node *node = NULL;

        if ( (node = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem (add_node)");
        }

        node->val = val;
        
        if (node->val < list->head->val) {

            node->next = list->head;
            list->head->prev = node;
            list->head = node;

            node->prev = NULL;

        } else {

            Node *tmp = list->head;
            while (tmp->next != NULL) {
    
                if (tmp->next->val > val) {
                    break;
                }
    
                tmp = tmp->next;
            }
    
            node->next = tmp->next;
            node->prev = tmp;

            if (tmp->next != NULL) {
                tmp->next->prev = node;
            }

            tmp->next = node;
   
        }

    }

    list->size++;
    list->sum += val;
    list->avg = list->sum / list->size;

    return;
}

void populate(List *list, unsigned int len) {

    for (size_t i = 0; i < len; i++) {

        add_node(list);

    }

    return;
}

void print_list(Node *node) {

    if (node == NULL) {

        puts("NULL");
        return;

    }

    printf("%3.0f->", node->val);
    print_list(node->next);
}
