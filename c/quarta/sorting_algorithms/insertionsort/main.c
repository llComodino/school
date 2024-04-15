#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1000

void insertion_sort(int *arr, size_t len);
void print_arr(int *arr, size_t len);
void populate_arr(int *arr, size_t len);

int main(void) {
  int arr[LEN];

  populate_arr(arr, LEN);

  puts("Unsorted Array:");
  print_arr(arr, LEN);

  insertion_sort(arr, LEN);

  puts("Sorted Array:");
  print_arr(arr, LEN);

  return 0;
}

void print_arr(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%3d", *(arr + i));
  }
  puts("\n");

  return;
}

void populate_arr(int *arr, size_t len) {
  srand(time(NULL));
  for (size_t i = 0; i < len; i++) {
    *(arr + i) = 1 + rand() % 100;
  }

  return;
}

void insertion_sort(int *arr, size_t len) {
  int temp;
  for (size_t i = 1; i < len; i++) {
    for (size_t j = i; j > 0 && *(arr + j - 1) > *(arr + j); j--) {
      temp = *(arr + j);
      *(arr + j) = *(arr + j - 1);
      *(arr + j - 1) = temp;
    }
  }
  return;
}

