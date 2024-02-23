#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    unsigned int val;
    struct Node *lft;
    struct Node *rgt;
} Node;

typedef struct {
    Node *root;
    unsigned int leaf_count;
    void (*traverse_in_order)(Node *root);
    void (*traverse_post_order)(Node *root);
    void (*traverse_pre_order)(Node *root);
} Tree;

void _init_tree(Tree **tree);
bool _is_empty(Tree *tree);
void in_order(Node *root);
void pre_order(Node *root);
void post_order(Node *root);
void add_leaf(Tree *tree, unsigned int val);

int main (void) {

    Tree *tree = NULL;

    _init_tree(&tree);

    for (size_t i = 10; i < 20; i++) {
        add_leaf(tree, i);
    }
    
    for (size_t i = 0; i < 10; i++) {
        add_leaf(tree, i);
    }

    printf("Number of leaves: %u\n\n", tree->leaf_count);

    puts("Traversals:\n===========\nIn Order:");
    tree->traverse_in_order(tree->root);
    
    puts("-----------\nPost Order:");
    tree->traverse_post_order(tree->root);
    
    puts("-----------\nPre Order:");
    tree->traverse_pre_order(tree->root);

    puts("-----------\n");

    return 0;
}

void _init_tree(Tree **tree) {

    if ( ((*tree) = (Tree*) malloc(sizeof(Tree))) == NULL) {
        fprintf(stderr, "Error initializing tree\nNot enough memory");
        exit(1);
    }

    (*tree)->root = NULL;
    (*tree)->traverse_in_order = in_order;
    (*tree)->traverse_post_order = post_order;
    (*tree)->traverse_pre_order = pre_order;
    (*tree)->leaf_count = 0;

    return;
}

bool _is_empty(Tree *tree) {
    return tree->root == NULL;
}

void in_order(Node *leaf) {

    if (leaf == NULL) {
        return;
    }
    
    in_order(leaf->lft);
    printf("%u\n", leaf->val);
    in_order(leaf->rgt);

    return;
}

void pre_order(Node *leaf) {
    
    if (leaf == NULL) {
        return;
    }
    
    printf("%u\n", leaf->val);
    in_order(leaf->lft);
    in_order(leaf->rgt);

    return;
}

void post_order(Node *leaf) {

    if (leaf == NULL) {
        return;
    }
    
    in_order(leaf->lft);
    in_order(leaf->rgt);
    printf("%u\n", leaf->val);

    return;
}

void add_leaf(Tree *tree, unsigned int val) {

    Node *tmp = tree->root;
    Node *parent = NULL;

    if (_is_empty(tree)) {

        if ( (tree->root = (Node*) malloc(sizeof(Node))) == NULL) {
            fprintf(stderr, "Error allocating root\nNot enough memory");
        }

        tree->root->val = val;
        tree->root->lft = NULL;
        tree->root->rgt = NULL;

    } else {

        while ( tmp != NULL && val != tmp->val ) {

            parent = tmp;

            if (val < tmp->val) {
                
                tmp = tmp->lft;
            
            } else if (val > tmp->val) {
            
                tmp = tmp->rgt;
            
            }

        }

        if (tmp == NULL) {
            
            if ( (tmp = (Node*) malloc(sizeof(Node))) == NULL ) {
                fprintf(stderr, "Error allocating leaf\nNot enough memory");
            }

            tmp->val = val;
            tmp->rgt = NULL;
            tmp->lft = NULL;
        
        } else {

            puts("Value already exists");

        }

        if (val < parent->val) {

            parent->lft = tmp;

        } else {

            parent->rgt = tmp;

        }

    }

    tree->leaf_count++;

    return;
}
