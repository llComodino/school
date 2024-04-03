#include <stdio.h>
#include <stdlib.h>

#define LEN_1 10
#define LEN_2 10

typedef struct Node {
    unsigned int num;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    unsigned int size;
} SortedList;

void __init_list(SortedList **);
void insert_sorted(SortedList *, int val);
void print_list(Node *);
void merge_list(SortedList *dest, SortedList *, SortedList *);

int main (void) {

    SortedList *list_1 = NULL;
    __init_list(&list_1);

    SortedList *list_2 = NULL;
    __init_list(&list_2);

    SortedList *merged = NULL;

    for (size_t i = 0; i < LEN_1; i++) {
        insert_sorted(list_1, 1 + rand() % 100);
    }
    
    for (size_t i = 0; i < LEN_1; i++) {
        insert_sorted(list_2, 1 + rand() % 100);
    }
    
    print_list(list_1->head);
    print_list(list_2->head);

    merge_list(merged, list_1, list_2);

    print_list(merged->head);
    return 0;
}

void __init_list(SortedList **list) {

    if ( ( (*list) = (SortedList*) malloc(sizeof(SortedList))) == NULL) {
        fprintf(stderr, "Not enough mem (__init)");
    }

    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;

    return;
}

void insert_sorted(SortedList *list, int val) {

    Node *tmp = list->head;
    if (list->head == NULL) {

        if ( (list->head = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem (insert_sorted)");
            exit(1);
        }

        list->head->num = val;
        list->head->next = NULL;
        list->tail = list->head;

    } else {

        Node *node = NULL;
        if ( (node = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem (insert_sorted)");
            exit(1);
        }

        node->num = val;
        node->next = NULL;

        if (val > list->tail->num) {

            list->tail->next = node;
            list->tail = node;

        } else if (val < list->head->num) {

            node->next = list->head;
            list->head = node;

        } else {

            while (tmp->next->num < val) {
                
                if (tmp->next == NULL) {
                    puts("Error");
                }

                tmp = tmp->next;
            }

            node->next = tmp->next;
            tmp->next = node;

        }

    }

    return;
}


        

void print_list(Node *node) {

    if (node == NULL) {

        puts("NULL");
        return;

    }

    printf("%3d->", node->num);
    print_list(node->next);
}

void merge_list(SortedList *dest, SortedList *src_1, SortedList *src_2) {

    if (src_1 == NULL || src_2 == NULL) {
        puts("One, or both lists are empty");
        return;
    }

    if (dest == NULL) {
        __init_list(&dest);
    }

    Node *tmp_dest = dest->head;
    Node *tmp_1 = src_1->head;
    Node *tmp_2 = src_2->head;
    int val = 0;

    while (tmp_1 != NULL && tmp_2 != NULL) {

        if (tmp_1->num > tmp_2->num) {

            val = tmp_2->num;
            tmp_2 = tmp_2->next;

        } else {

            val = tmp_1->num;
            tmp_1 = tmp_1->next;

        }

        if ( dest->head == NULL ) {

            if ( (dest->head = (Node*) malloc(sizeof(Node))) == NULL) {
                fprintf(stderr, "Not enough mem (merge_list)");
            }

            dest->head->num = val;
            dest->head->next = NULL;
            tmp_dest = dest->head;
            dest->tail = dest->head;

        } else {

            while (tmp_dest->next != NULL) {
                tmp_dest = tmp_dest->next;
            }

            if ( (tmp_dest->next = (Node*) malloc(sizeof(Node))) == NULL) {
                fprintf(stderr, "Not enough mem (merge_list)");
            }

            tmp_dest->next->num = val;
            tmp_dest->next->next = NULL;

            dest->tail = tmp_dest->next;
            tmp_dest = tmp_dest->next;

        }
        
    }

    while (tmp_1 != NULL) {

        if ( (tmp_dest->next = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem (merge_list)");
        }

        tmp_dest->next->num = tmp_1->num;
        tmp_dest->next->next = NULL;

        dest->tail = tmp_dest->next;
        tmp_dest = tmp_dest->next;
        tmp_1 = tmp_1->next;

    }

    while (tmp_2 != NULL) {

        if ( (tmp_dest->next = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem (merge_list)");
        }

        tmp_dest->next->num = tmp_2->num;
        tmp_dest->next->next = NULL;

        dest->tail = tmp_dest->next;
        tmp_dest = tmp_dest->next;
        tmp_2 = tmp_2->next;

    }

    return;
}
