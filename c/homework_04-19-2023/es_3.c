#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void populate_array(int *const, size_t size);
void print_array(const int *const, size_t size);
int count_distinct_elements(const int *);
bool is_distinct(const int *const pe, const int *const parr);
void fill_distincts(const int *const, int *const, size_t size);

int main(void) {
  srand(time(NULL));

  int arr[SIZE];
  populate_array(arr, SIZE);
  print_array(arr, SIZE);

  int counter = count_distinct_elements(arr);
  printf("\nThere are %d distinct elements, so the new array wll be of the "
         "same dimension\n",
         counter);

  int distincts[counter];
  fill_distincts(arr, distincts, SIZE);
  print_array(distincts, counter);

  return 0;
}

void populate_array(int *const parr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    *(parr + i) = 1 + rand() % 20;
  }
}

void print_array(const int *const parr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%4d", *(parr + i));
  }
  puts("");
}

int count_distinct_elements(const int *const parr) {
  int c = 0;
  for (size_t i = 0; i < SIZE; i++) {
    if (is_distinct(parr + i, parr)) {
      c++;
    }
  }
  return c;
}

bool is_distinct(const int *const pe, const int *const parr) {
  for (size_t i = 0; i < SIZE; i++) {
    if (pe != parr + i) {
      if (*pe == *(parr + i)) {
        return false;
      }
    }
  }
  return true;
}

void fill_distincts(const int *const parr, int *const pdis, size_t size) {
  for (size_t i = 0, c = 0; i < size; i++) {
    if (is_distinct(parr + i, parr)) {
      *(pdis + c++) = *(parr + i);
    }
  }
}

