#include <stdio.h>

// Funzione che si avvale dei pointer
// per poter scambiare di posto i valori
void swap(int *px, int *py) {
  int temp = *px;
  *px = *py;
  *py = temp;
}

// Creo il bubble sort
void BubbleSort(int arr[], int n) {
  int x, y;
  for (x = 0; x < n - 1; x++)
    for (y = 0; y < n - x - 1; y++)
      if (arr[y] > arr[y + 1])
        swap(&arr[y], &arr[y + 1]);
}

// Funzione che stampa l'array
void PrintArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);

  printf("n");
}

// Test delle funzioni superiori
int main() {
  int arr[10];

  for (int i = 0; i < 10; i++) {
    printf("Compila il vettore: ");
    scanf("%d", &arr[i]);
  }

  int n = sizeof(arr) / sizeof(arr[0]);

  BubbleSort(arr, n);
  printf("\nArray ordinato: ");
  PrintArray(arr, n);
}