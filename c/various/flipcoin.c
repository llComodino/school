#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);

int main(void) {
  srand(time(NULL));

  char p = 37;
  int t = 0;
  int c = 0;

  for (int i = 1; i <= 6000; i++) {
    int l = flip();

    if (l == 0)
      t++;

    else
      c++;
  }
  printf("Testa: %.1f%c\nCroce: %.1f%c\n", (float)t * 100 / 6000, p,
         (float)c * 100 / 6000, p);
  return 0;
}

int flip(void) {
  int f = rand() % 2;
  return f;
}
