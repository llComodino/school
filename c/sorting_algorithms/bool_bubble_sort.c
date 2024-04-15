// Diego Gila		3Ein
// Bubble sort efficiente con una sola funzione
#include <stdbool.h>
#include <stdio.h>

#define MAX_ARR 1000

void bubble_sort(int vett[], int dim) {
  bool scambi;
  do {
    scambi = false;
    for (int i = 0; i < dim - 1; i++)
      if (vett[i + 1] < vett[i]) {
        int temp = vett[i];
        vett[i] = vett[i + 1];
        vett[i + 1] = temp;
        scambi = true;
      }
  } while (scambi == true);
}

int main() {
  int arr[MAX_ARR];
  for (int i = 0; i < MAX_ARR; i++)
    arr[i] = MAX_ARR - i;

  int dim = sizeof(arr) / 4;
  bubble_sort(arr, dim);

  for (int i = 0; i < MAX_ARR; i++) {
    if ((i % 20) == 0)
      printf("\n");
    printf("%d\t", arr[i]);
  }
}
