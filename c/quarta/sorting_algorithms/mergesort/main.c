#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100000

void mergesort(int *arr, int left, int right);
void print_array(int *arr, size_t len);
void populate_array(int *arr, size_t len);

int main(void) {
  int arr[LEN];
  populate_array(arr, LEN);

  printf("Given array is \n");
  print_array(arr, LEN);

  mergesort(arr, 0, LEN - 1);

  printf("\nSorted array is \n");
  print_array(arr, LEN);

  return 0;
}

void populate_array(int *arr, size_t len) {
  srand(time(NULL));
  for (size_t i = 0; i < len; i++) {
    *(arr + i) = 1 + rand() % 100;
  }
  return;
}

void merge(int arr[], int l, int m, int r) {
  size_t i, j, k;
  size_t n1 = m - l + 1;
  size_t n2 = r - m;

  int left[n1], right[n2];

  for (i = 0; i < n1; i++) {
    left[i] = arr[l + i];
  }

  for (j = 0; j < n2; j++) {
    right[j] = arr[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {

    if (left[i] <= right[j]) {

      arr[k] = left[i];
      i++;

    } else {

      arr[k] = right[j];
      j++;
    }

    k++;
  }

  while (i < n1) {

    arr[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {

    arr[k] = right[j];
    j++;
    k++;
  }

  return;
}

void mergesort(int arr[], int left, int right) {

  if (left < right) {
    int middle = left + (right - left) / 2;

    mergesort(arr, left, middle);
    mergesort(arr, middle + 1, right);

    merge(arr, left, middle, right);
  }

  return;
}

void print_array(int *arr, size_t len) {

  for (size_t i = 0; i < len; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");

  return;
}
