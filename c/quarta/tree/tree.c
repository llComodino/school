#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Leaf {
  int val;
  struct Leaf *top;
  struct Leaf *lft;
  struct Leaf *rgt;
} Leaf;

typedef struct {

  Leaf *root;

  unsigned int leaves_count;
  double sum;
  double avg;
  double lft_sum;
  double rgt_sum;
  double lft_avg;
  double rgt_avg;

  void (*in_order)(Leaf *leaf);
  void (*pre_order)(Leaf *leaf);
  void (*post_order)(Leaf *leaf);

} Tree;

void _init_tree(Tree **tree);
void in_order(Leaf *leaf);
void pre_order(Leaf *leaf);
void post_order(Leaf *leaf);
void add_leaf(Tree *tree, const unsigned int *const val);

int main(void) {

  Tree *tree = NULL;

  _init_tree(&tree);

  unsigned int val = 0;

  for (size_t i = 10; i < 20; i++) {

    if (i % 2) {

      val = 20 - i;

    } else {

      val = i;
    }

    add_leaf(tree, &val);
  }

  tree->in_order(tree->root);
  puts("");

  tree->pre_order(tree->root);
  puts("");

  tree->post_order(tree->root);
  puts("");

  printf("%d%6.2f%6.2f\n\n", tree->leaves_count, tree->sum, tree->avg);

  return 0;
}

void _init_tree(Tree **tree) {

  if (((*tree) = (Tree *)malloc(sizeof(Tree))) == NULL) {
    fprintf(stderr, "Not enough mem");
  }

  (*tree)->root = NULL;

  (*tree)->leaves_count = 0;
  (*tree)->sum = 0;
  (*tree)->avg = 0;
  (*tree)->lft_sum = 0;
  (*tree)->rgt_sum = 0;
  (*tree)->lft_avg = 0;
  (*tree)->rgt_avg = 0;

  (*tree)->in_order = in_order;
  (*tree)->pre_order = pre_order;
  (*tree)->post_order = post_order;

  return;
}

void in_order(Leaf *leaf) {

  if (leaf == NULL) {
    return;
  }

  in_order(leaf->lft);

  printf("%5d", leaf->val);

  in_order(leaf->rgt);

  return;
}

void pre_order(Leaf *leaf) {

  if (leaf == NULL) {
    return;
  }

  printf("%5d", leaf->val);

  pre_order(leaf->lft);

  pre_order(leaf->rgt);

  return;
}

void post_order(Leaf *leaf) {

  if (leaf == NULL) {
    return;
  }

  post_order(leaf->lft);

  post_order(leaf->rgt);

  printf("%5d", leaf->val);

  return;
}

void add_leaf(Tree *tree, const unsigned int *const val) {

  Leaf *tmp = tree->root;
  Leaf *node = NULL;

  while (tmp != NULL) {

    node = tmp;

    if (tmp->val == *val) {
      puts("Value already in there");
      return;
    }

    if (*val < tmp->val) {

      tmp = tmp->lft;

    } else {

      tmp = tmp->rgt;
    }
  }

  if (tmp != NULL) {
    fprintf(stderr, "Something wrong appened travesing the tree");
    exit(2);
  }

  if (tree->root == tmp) {

    if ((tree->root = (Leaf *)malloc(sizeof(Leaf))) == NULL) {
      fprintf(stderr, "Not enough mem");
    }

    tree->root->val = (*val);
    tree->root->lft = NULL;
    tree->root->rgt = NULL;
    tree->root->top = NULL;

  } else {

    if (*val < node->val) {

      if ((node->lft = (Leaf *)malloc(sizeof(Leaf))) == NULL) {
        fprintf(stderr, "Not enough mem");
        exit(1);
      }

      tmp = node->lft;

    } else {

      if ((node->rgt = (Leaf *)malloc(sizeof(Leaf))) == NULL) {
        fprintf(stderr, "Not enough mem");
        exit(1);
      }

      tmp = node->rgt;
    }

    tmp->val = *val;
    tmp->top = node;
    tmp->lft = NULL;
    tmp->rgt = NULL;
  }

  tree->leaves_count++;
  tree->sum += (*val);
  tree->avg = tree->sum / tree->leaves_count;

  return;
}

