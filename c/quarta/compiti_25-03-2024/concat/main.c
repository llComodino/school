#include <stdio.h>
#include <stdlib.h>

#define LIST_1 10
#define LIST_2 5

typedef struct Node {
  char c;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  unsigned int size;
} List;

void __init_list(List **list);
void populate(List *list, unsigned int len);
void add_node(List *list, char c);
void print_list(Node *node);
void concatenate(List *dest, List *src);

int main(void) {

  List *list_1 = NULL;
  __init_list(&list_1);
  List *list_2 = NULL;
  __init_list(&list_2);

  populate(list_1, LIST_1);
  print_list(list_1->head);

  puts("");
  puts("");

  populate(list_2, LIST_2);
  print_list(list_2->head);

  puts("");
  puts("");

  concatenate(list_2, list_1);
  print_list(list_2->head);
  return 0;
}

void __init_list(List **list) {

  if (((*list) = (List *)malloc(sizeof(List))) == NULL) {
    fprintf(stderr, "Not enough mem (__init_list)");
  }

  (*list)->head = NULL;
  (*list)->tail = NULL;

  (*list)->size = 0;

  return;
}

void populate(List *list, unsigned int len) {

  for (size_t i = 0; i < len; i++) {
    add_node(list, 64 + rand() % 26);
  }

  return;
}

void add_node(List *list, char c) {

  Node *tmp = list->head;

  if (list->head == NULL) {

    if ((list->head = (Node *)malloc(sizeof(Node))) == NULL) {
      fprintf(stderr, "Not enough mem (add_node)");
    }

    list->head->c = 64 + rand() % 26;
    list->head->next = NULL;
    list->head->prev = NULL;

    list->tail = list->head;

  } else {

    while (tmp->next != NULL) {
      tmp = tmp->next;
    }

    if ((tmp->next = (Node *)malloc(sizeof(Node))) == NULL) {
      fprintf(stderr, "Not enough mem (add_node)");
    }

    tmp->next->c = 64 + rand() % 26;

    tmp->next->next = NULL;
    tmp->next->prev = tmp;

    list->tail = tmp->next;
  }

  list->size++;

  return;
}

void print_list(Node *node) {

  if (node == NULL) {
    return;
  }

  printf("%c ->", node->c);

  print_list(node->next);
}

void concatenate(List *dest, List *src) {

  dest->tail->next = src->head;
  dest->size += src->size;

  return;
}

