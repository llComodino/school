#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER 256
#define BASE_NUM 100

typedef enum {
    AVIABLE,
    NAVIABLE,
} BookStatus;

typedef struct Book {
    char *title;
    char *author;
    BookStatus status;
    struct Book *next;
} Book;

typedef struct Node {
    char *name;
    char *surname;
    unsigned int num;
    Book *books;
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
void load_books(Book *books);
void print_books(Book *book);
void insert_end(List *list, char *name, char *surname, unsigned int num);
void insert_index(List *list, int idx, char *name, char *surname, unsigned int num);
void print_list(Node *head);
unsigned int get_choice(void);
void book(List *list, Book *books, unsigned int number);

int main(void) {
    
    List *list;
    Book *books;
    initialize_list(&list);
    load_books(books);

    unsigned int choice = 0;

    char *name = NULL;
    char *surname = NULL;

    if ( (name = (char*) malloc(sizeof(char) * BUFFER)) == NULL) {
        fprintf(stderr, "Error assignin memory to name (main)");
    }
    
    if ( (surname = (char*) malloc(sizeof(char) * BUFFER)) == NULL) {
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
 
                num = BASE_NUM + list->size;

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

            case 3:

                if (list->head == NULL) {

                    puts("List is empty");
                    break;

                }

                unsigned int student = BASE_NUM;
                puts("Who would like to read a book? ");
                print_list(list->head);
                do {
                    fscanf(stdin, "%d", &student);
                } while (student < BASE_NUM || student > BASE_NUM + list->size);

                book(list, books, student);
                break;

            case 4:
                print_books(books);
                break;
        
            case 0:
                puts("Bye");
                break;

            default:
                fprintf(stderr, "Error, reached default in switch case (main)\nShould NOT be possible");
                break;
        }

    } while (choice != 0);

    return 0;
}

void create_node(Node** node, char* name, char* surname, unsigned int num) {
    
    *node = (Node*)malloc(sizeof(Node));
    (*node)->name = strdup(name);
    (*node)->surname = strdup(surname);
    (*node)->num = num;
    (*node)->books = NULL;
    (*node)->prev = NULL;
    (*node)->next = NULL;

    return;
}

void initialize_list(List** list) {
 
    *list = (List*)malloc(sizeof(List));
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;

    return;
}

void load_books(Book *books) {

    FILE *file = NULL;
    
    if ( (file = fopen("libri.txt", "r")) == NULL ) {
        fprintf(stderr, "Error opening file (load_books)");
        exit(1);
    }

    char *buffer = (char *) malloc(sizeof(char) * BUFFER);
    
    if ( books == NULL && fgets(buffer, BUFFER, file) != NULL) {

        if ( ( books = (Book *) malloc(sizeof(Book))) == NULL) {
            fprintf(stderr, "Not enough mem (load_books)");
        }

        books->title = strtok(buffer, ";");
        books->author = strtok(NULL, ";");
        books->status = (int)*(strtok(NULL, ";")) - 48;

        books->next = NULL;

    } else {

        puts("Error");
        exit(1);

    }

    Book *tmp = books;
    while ( fgets(buffer, BUFFER, file) != NULL ) {

        if ( ( tmp->next = (Book *) malloc(sizeof(Book))) == NULL) {
            fprintf(stderr, "Not enough mem (load_books)");
        }

        tmp->next->title = strtok(buffer, ";");
        tmp->next->author = strtok(NULL, ";");
        tmp->next->status = (int)*(strtok(NULL, ";")) - 48;
        tmp->next->next = NULL;
        
        tmp = tmp->next;

    }

    fclose(file);

    return;
}

void print_books(Book *book) {
    
    if (book == NULL) {

        return;

    }

    printf("%8s: %s\n%8s: %s\n%8s: %s\n-----------------------\n", "Title", book->title, "Author", book->author, "Aviable", book->status ? "No" : "Yes");
    print_books(book->next);

}

void insert_end(List* list, char* name, char* surname, unsigned int num) {
    
    Node* node;
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

void insert_index(List* list, int index, char* name, char* surname, unsigned int num) {
    
    if (index < 0 || index > list->size) {
    
        printf("Invalid index\n");
        return;
    
    }

    Node* node;
    create_node(&node, name, surname, num);

    if (index == 0) {
        
        node->next = list->head;
        
        if (list->head != NULL) {
        
            list->head->prev= node ;
            
        } else {
            
            list->tail= node ; 
        }
        
        list->head = node;
    
    } else if (index == list->size) {
        
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    
    } else {
        
        Node* current = list->head;
        
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

    printf("Name: %s\nSurname: %s\nNumber: %u\n-------------\n", head->name, head->surname, head->num);

    print_list(head->next);
}

unsigned int get_choice(void) {

    unsigned int choice = 0;

    puts("1. Print List");
    puts("2. Add Student");
    puts("3. Book");
    puts("4. Print Books");
    puts("0. Exit");

    do {
        scanf("%u", &choice);
    } while (choice < 0 || choice > 4);

    return choice;
}

void book(List *list, Book *books, unsigned int number) {

    void find_student(Node *, unsigned int *);
    void select_book(Book *books, Book *book);
    Node *tmp = list->head;

    find_student(tmp, &number);

    if (tmp == NULL) {

        printf("Student %d does not exist!\n\n", number);
        return;

    }

    Book *book = tmp->books;
    if (book == NULL) {
       
        if ( (book = (Book *) malloc(sizeof(Book))) == NULL) {
            fprintf(stderr, "Not enough mem (book)");
        }
        
    } else {

        while (book->next != NULL) {

            book = book->next;

        }

        if ( (book->next = (Book *) malloc(sizeof(Book))) == NULL) {
            fprintf(stderr, "Not enough mem (book)");
        }

        book = book->next;

    }

    select_book(books, book);

    return;
}

void find_student(Node *node, unsigned int *number) {
    
    if ( node->num == *number ) {
        return;
    }

    if ( node == NULL) {
        return;
    }

    node = node->next;
    find_student(node, number);

    return;
}

void select_book(Book *books, Book *book) {

    if (books == NULL) {
        puts("No more books\n");
        return;
    }

    printf("%8s: %s\n%8s: %s\n%8s: %s\n-----------------------\n", "Title", books->title, "Author", books->author, "Aviable", books->status ? "No" : "Yes");
    printf("Get this book? [y/n]: ");
    char sel;
    do {
        fscanf(stdin, "%c", &sel);
    } while (sel != 'y' && sel != 'n' && sel != 'Y' && sel != 'N');

    if (sel == 'y' || sel == 'Y') {

        if (books->status == NAVIABLE) {

            puts("Sorry, this book is not aviable!");

        } else {

            book->title = strdup(books->title);
            book->author = strdup(books->author);
            book->status = NAVIABLE;
            books->status = NAVIABLE;
            
        }

    }

    return;
}
