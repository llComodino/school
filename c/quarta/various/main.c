#include <stdio.h>

#define TRIANGLE_ROWS 10

void floyd (unsigned int rows) {
  int tot = 0;
  for (size_t i = 1; i < rows; i ++) {
    for (size_t j = i; j < i * 2; j++) {
      tot += 1;
      printf("%4d", tot);
    }
    puts("");
  }
  return;
}

int main (void) {

  floyd(TRIANGLE_ROWS);
  
  return 0;
}

