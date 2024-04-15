// Diego Gila       3Ein
// Programma 3
#include <stdio.h>

int main(void) {
  int h, m, s;

  do {
    printf("Insert hours, minutes and seconds: ");
    scanf("%d%d%d", &h, &m, &s);
  } while (h < 0 || h > 24 || m < 0 || m > 59 || s < 0 || s > 59);

  long sf = 0;

  if (h <= 12)
    sf += ((12 + h) * 3600) + m * 60 + s;

  if (h > 12)
    sf += ((h - 12) * 3600) + m * 60 + s;

  printf("Total seconds: %ld", sf);
  return 0;
}