#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    unsigned int num;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    unsigned int size;
} SortedList;

void insert_sorted(SortedList *, int val);
void print_list(Node *);
void merge_list(SortedList *dest, SortedList *src);

int main (void) {

    return 0;
}

void insert_sorted(SortedList *, int val);
void print_list(Node *);
void merge_list(SortedList *dest, SortedList *src);
