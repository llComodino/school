// Diego Gila
#include <math.h>
#include <stdio.h>

int main(void) {
  float n;

  do {
    printf("Inserire un numero decimale [0 per terminare]: ");
    scanf("%f", &n);

    if (n != 0)
      printf("valore di partenza: %.2f\nIl valore approssimato vale: %.0f\n\n",
             n, floor(n + .5));
  } while (n != 0);
  return 0;
}