/* Binary Search Tree
 * Author: Comodino
 *
 * This program implements a binary search tree.
 * The user can add numbers to the tree and print it
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

unsigned int select_option (void);
void add_number (struct Node *root);
void print_tree (struct Node *root);

int main (void) {

    struct Node *root = NULL;
    
    if ( ( root = (struct Node *) malloc (sizeof (struct Node)) ) == NULL ) {
        printf ("Error: malloc failed in main\n");
        return 1;
    }

    root->data = 0;

    unsigned int option = 0;
    while ( ( option = select_option () ) != 0 ) {
        switch ( option ) {
            case 1:
                add_number (root);
                break;
            case 2:
                print_tree (root);
                break;
            default:
                printf ("Error: invalid option\n");
                break;
        }
    }

    return 0;
}

unsigned int select_option (void) {

    unsigned int option = 0;

    printf ("Select an option:\n");
    printf ("1. Add a number to the tree\n");
    printf ("2. Print the tree\n");
    printf ("0. Exit\n");
    printf ("Option: ");
    scanf ("%d", &option);

    return option;
}

void add_number (struct Node *root) {

    int number = 0;

    printf ("Enter a number to add to the tree: ");
    scanf ("%d", &number);

    if (root->data == 0) {
        root->data = number;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        struct Node *current = root;
        struct Node *previous = NULL;

        while (current != NULL) {
            previous = current;
            if (number < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (number < previous->data) {
            previous->left = (struct Node *) malloc (sizeof (struct Node));
            previous->left->data = number;
            previous->left->left = NULL;
            previous->left->right = NULL;
        }
        else {
            previous->right = (struct Node *) malloc (sizeof (struct Node));
            previous->right->data = number;
            previous->right->left = NULL;
            previous->right->right = NULL;
        }
    }
}

void print_tree (struct Node *root) {

    if (root != NULL) {
        print_tree (root->left);
        printf ("%d\n", root->data);
        print_tree (root->right);
    }
}
