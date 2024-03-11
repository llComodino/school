#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
    bool (*is_empty)(const struct Queue *const);
    void (*print)(const Node *const);
    int (*push)(struct Queue *const, const int *const);
    int (*pop)(struct Queue *const);
} Queue;

void _init_queue(Queue **);
bool _is_empty(const Queue *const);
void print_queue(const Node *const);
int push(Queue *const, const int *const val);
int pop(Queue *const);

int main (void) {

    Queue *queue = NULL;
    _init_queue(&queue);

    queue->print(queue->head);

    for (int i = 0; i < 10; i++) {

        printf("Pushed %d\n", queue->push(queue, &i));

    }

    puts("\n");
    
    queue->print(queue->head);

    puts("\n");

    int popped_val = 0;
    for (size_t i = 0; i < 11; i++) {

        popped_val = queue->pop(queue);
        if (popped_val != -1) {
         
            printf("Popped: %d\n", popped_val);
        
        }
    
    }

    queue->print(queue->head);

    return 0;
}

void _init_queue(Queue **queue) {

    if ( ( (*queue) = (Queue *) malloc(sizeof(Queue))) == NULL) {
        fprintf(stderr, "Not enough mem");
        exit(1);
    }

    (*queue)->head = NULL;
    (*queue)->tail = NULL;

    (*queue)->size = 0;

    (*queue)->pop = pop;
    (*queue)->push = push;
    (*queue)->print = print_queue;
    (*queue)->is_empty = _is_empty;

    return;
}

bool _is_empty(const Queue *const queue) {

    return (queue->head == NULL);

}

void print_queue(const Node *const node) {

    if (node == NULL) {

        return;

    }

    printf("%d -> ", node->val);
    print_queue(node->next);
}

int push(Queue *const queue, const int *const val) {

    if (queue->head == NULL) {

        if ( (queue->head = (Node *) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not enough mem");
            exit(1);
        }

        queue->head->prev = NULL;
        queue->head->next = NULL;

        queue->head->val = *val;

        queue->tail = queue->head;

    } else {

        if ( (queue->tail->next = (Node *) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Not nough mem");
            exit(1);
        }

        queue->tail->next->prev = queue->tail;
        queue->tail->next->next = NULL;
        queue->tail->next->val = *val;

        queue->tail = queue->tail->next;
    }

    return (*val);
}


int pop(Queue *const queue) {

    int val = -1;

    if (queue->is_empty(queue)) {
    
        puts("Queue is empty");

    } else {

        val = queue->head->val;
        queue->head = queue->head->next;
    
    }

    return val;
}
