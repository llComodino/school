#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void populate_array(int *const, size_t);
void print_array(int *const, size_t);
void bubble_sort(int *const, size_t,
                 bool (*order)(const int *const, const int *const));
bool ascend(const int *const, const int *const);
bool descend(const int *const, const int *const);

int main(void) {

  int vec[SIZE];

  populate_array(vec, SIZE);
  print_array(vec, SIZE);

  int order;
  puts("1. Ascending order\n2. Descending order");
  scanf("%d", &order);

  if (order == 1) {
    bubble_sort(vec, SIZE, ascend);
  } else if (order == 2) {
    bubble_sort(vec, SIZE, descend);
  }

  print_array(vec, SIZE);

  return 0;
}

void populate_array(int *const parr, size_t size) {

  for (size_t i = 0; i < size; i++) {
    *(parr + i) = 1 + rand() % 50;
  }
  return;
}

void print_array(int *const parr, size_t size) {

  for (size_t i = 0; i < size; i++) {
    printf("%4d", *(parr + i));
  }
  puts("");
  return;
}

void bubble_sort(int *const parr, size_t size,
                 bool (*order)(const int *const, const int *const)) {

  void swap(int *const, int *const);

  bool swapping;
  do {
    swapping = false;
    for (size_t i = 0; i < size - 1; i++) {
      if ((*order)(parr + i, parr + i + 1)) {
        swap(parr + i, parr + i + 1);
        swapping = true;
      }
    }
  } while (swapping == true);
  return;
}

void swap(int *const pe1, int *const pe2) {

  int hold = *pe1;
  *pe1 = *pe2;
  *pe2 = hold;

  return;
}

bool ascend(const int *const pe1, const int *const pe2) { return *pe1 > *pe2; }

bool descend(const int *const pe1, const int *const pe2) { return *pe1 < *pe2; }

