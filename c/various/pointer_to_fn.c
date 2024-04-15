#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define SIZE 10

void print_array(const short *const pa);
void bubble(short *work, size_t, bool (*compare)(const short, const short));
bool ascend(const short, const short);
bool descend(const short, const short);

int main(void) {
  short a[SIZE] = {3, 5, 2, 4, 1, 9, 6, 8, 7, 0};

  puts("Enter 1 to ascend\nEnter 2 to descend");
  int order;
  scanf("%d", &order);

  puts("Datas in original order: ");
  print_array(a);

  if (order == 1) {
    bubble(a, SIZE, ascend);
    puts("Data items in ascending order:");
  } else {
    bubble(a, SIZE, descend);
    puts("Data items in ascending order:");
  }

  print_array(a);

  return 0;
}

void print_array(const short *const pa) {
  for (size_t i = 0; i < SIZE; i++) {
    printf("%d\t", *(pa + i));
  }
  puts("");
}

void bubble(short *const work, size_t size,
            bool (*compare)(const short a, const short b)) {
  void swap(short *const pe1, short *const pe2);

  for (unsigned int pass = 1; pass < SIZE; pass++) {
    for (size_t i = 0; i < SIZE - 1; i++) {
      if ((*compare)(*(work + i), *(work + i + 1))) {
        swap(work + i, work + i + 1);
      }
    }
  }
}

void swap(short *const pe1, short *const pe2) {
  short hold = *pe1;
  *pe1 = *pe2;
  *pe2 = hold;
}

bool asced(const short a, const short b) { return a > b; }

bool desced(const short a, const short b) { return a < b; }
