#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100

void selection_sort(int *arr, size_t len);
void populate_arr(int *arr, size_t len);
void print_arr(int *arr, size_t len);

int main(void) {
  int arr[LEN];

  populate_arr(arr, LEN);

  puts("Unsorted Array:");
  print_arr(arr, LEN);

  selection_sort(arr, LEN);

  puts("Sorted Array:");
  print_arr(arr, LEN);

  return 0;
}

void selection_sort(int *arr, size_t len) {
  int *min_ptr, min_index;
  int temp;

  for (size_t i = 0; i < len - 1; i++) {
    min_index = i;
    min_ptr = &*(arr + min_index);

    for (size_t j = i + 1; j < len; j++) {
      if (*(arr + j) < *min_ptr) {
        min_index = j;
        min_ptr = &*(arr + min_index);
      }
    }

    if (min_index != i) {
      temp = *(arr + i);
      *(arr + i) = *min_ptr;
      *min_ptr = temp;
    }
  }
}

void populate_arr(int *arr, size_t len) {
  srand(time(NULL));

  for (size_t i = 0; i < len; i++) {
    *(arr + i) = 1 + rand() % 100;
  }

  return;
}

void print_arr(int *arr, size_t len) {

  for (size_t i = 0; i < len; i++) {
    printf("%4d", *(arr + i));
  }
  puts("\n");

  return;
}

