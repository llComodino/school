#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 32

typedef struct Node {
  char *name;
  char *surname;
  unsigned int num;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int size;
} List;

void create_node(Node **node, char *name, char *surname, unsigned int num);
void initialize_list(List **list);
void insert_end(List *list, char *name, char *surname, unsigned int num);
void insert_index(List *list, int idx, char *name, char *surname,
                  unsigned int num);
void print_list(Node *head);
unsigned int get_choice(void);

int main(void) {

  List *list;
  initialize_list(&list);

  unsigned int choice = 0;

  char *name = NULL;
  char *surname = NULL;

  if ((name = (char *)malloc(sizeof(char) * BUFFER)) == NULL) {
    fprintf(stderr, "Error assignin memory to name (main)");
  }

  if ((surname = (char *)malloc(sizeof(char) * BUFFER)) == NULL) {
    fprintf(stderr, "Error assignin memory to surname (main)");
  }

  unsigned int num;

  do {
    choice = get_choice();

    switch (choice) {

    case 1:
      print_list(list->head);
      break;

    case 2:

      printf("Insert name: ");
      do {
        fgets(name, BUFFER, stdin);
      } while (strlen(name) < 2);
      *(name + strlen(name) - 1) = '\0';

      printf("Insert surname: ");
      do {
        fgets(surname, BUFFER, stdin);
      } while (strlen(surname) < 2);
      *(surname + strlen(surname) - 1) = '\0';

      printf("Insert number [100 - 999]: ");
      do {
        scanf("%u", &num);
      } while (num < 100);

      int idx = 0;

      printf("Insert index - [-1] to append: ");
      do {
        printf("Current list size: %d\n", list->size);
        scanf("%d", &idx);
      } while (idx < -1 || idx > list->size - 1);

      if (idx == -1) {
        insert_end(list, name, surname, num);
      } else {
        insert_index(list, idx, name, surname, num);
      }
      break;

    case 0:
      puts("Bye");
      break;

    default:
      fprintf(stderr, "Error, reached default in switch case (main)\nShould "
                      "NOT be possible");
      break;
    }

  } while (choice != 0);

  return 0;
}

void create_node(Node **node, char *name, char *surname, unsigned int num) {
  *node = (Node *)malloc(sizeof(Node));
  (*node)->name = strdup(name);
  (*node)->surname = strdup(surname);
  (*node)->num = num;
  (*node)->prev = NULL;
  (*node)->next = NULL;

  return;
}

void initialize_list(List **list) {

  *list = (List *)malloc(sizeof(List));
  (*list)->head = NULL;
  (*list)->tail = NULL;
  (*list)->size = 0;

  return;
}

void insert_end(List *list, char *name, char *surname, unsigned int num) {

  Node *node;
  create_node(&node, name, surname, num);

  if (list->head == NULL) {

    list->head = node;
    list->tail = node;

  } else {

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
  }

  list->size++;

  return;
}

void insert_index(List *list, int index, char *name, char *surname,
                  unsigned int num) {

  if (index < 0 || index > list->size) {

    printf("Invalid index\n");
    return;
  }

  Node *node;
  create_node(&node, name, surname, num);

  if (index == 0) {

    node->next = list->head;

    if (list->head != NULL) {

      list->head->prev = node;

    } else {

      list->tail = node;
    }

    list->head = node;

  } else if (index == list->size) {

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;

  } else {

    Node *current = list->head;

    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }

    node->next = current->next;
    node->prev = current;
    current->next->prev = node;
    current->next = node;
  }

  list->size++;

  return;
}

void print_list(Node *head) {

  if (head == NULL) {
    return;
  }

  printf("Name: %s\nSurname: %s\nNumber: %u\n-------------\n", head->name,
         head->surname, head->num);

  print_list(head->next);
}

unsigned int get_choice(void) {

  unsigned int choice = 0;

  puts("1. Print List");
  puts("2. Add Student");
  puts("0. Exit");

  do {
    scanf("%u", &choice);
  } while (choice < 0 || choice > 4);

  return choice;
}
