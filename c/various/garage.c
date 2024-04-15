// Diego Gila       3Ein
#include <stdio.h>

int main(void) {
  float h;

  for (int i = 1; i <= 3; i++) {
    printf("Inserire il numero di ore del cliente %d: ", i);
    scanf("%f", &h);

    if (h <= 3)
      printf("Importo da pagare: %.2f\n", h * 2.0);

    if (h > 3)
      if ((h * 2.0 + 0.50 * h - 3.0) <= 10)
        printf("Importo da pagare: %.2f\n", h * 2.0 + 0.50 * h - 3.0);
      else
        printf("Importo massimo di 10 euro raggiunto\n");
  }
  return 0;
}