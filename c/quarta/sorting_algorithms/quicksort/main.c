#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100000

void swap(int *a, int *b);
int partition(int *arr, int low, int high);
void quick_sort(int *arr, int low, int high);
void populate_arr(int *arr, size_t len);
void print_arr(int *arr, size_t len);

int main(void) {
  int arr[LEN];

  populate_arr(arr, LEN);

  puts("Unsorted Arr:");
  print_arr(arr, LEN);

  quick_sort(arr, 0, LEN - 1);

  puts("Sorted Arr:");
  print_arr(arr, LEN);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return i + 1;
}

void quick_sort(int *arr, int low, int high) {
  if (low < high) {
    int pivot_index = partition(arr, low, high);
    quick_sort(arr, low, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, high);
  }

  return;
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
    fprintf(stdout, "%4d", *(arr + i));
  }
  puts("\n");

  return;
}
