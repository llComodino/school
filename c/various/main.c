#include <stdio.h>

#define AGENTS 4
#define COLUMNS 3
#define ELEMENTS 5

void printMatrix(const double distinte[AGENTS][COLUMNS][ELEMENTS]);

int main(void) {
  double distinte[AGENTS][COLUMNS][ELEMENTS] = {
      {{10.0, 12.0, 13.0, 15.0, 104.0}, {0}, {0}},
      {{10.0, 12.0, 13.0, 15.0, 104.0}, {0}, {0}},
      {{10.0, 12.0, 13.0, 15.0, 104.0}, {0}, {0}},
      {{10.0, 12.0, 13.0, 15.0, 104.0}, {0}, {0}}};

  int np, qnt;

  for (int j = 1; j <= 2; j++) {
    printf("Giorno %d\n\n", j + 1);
    for (int i = 0; i < 4; i++) {
      printf("Agente %d", i + 1);
      do {
        printf("Numero prd (0 per terminare): ");
        scanf("%d", &np);

        if (np > 0 && np < 6) {
          printf("Qnt: ");
          scanf("%d", &qnt);
          distinte[i][j][np - 1] += distinte[i][0][np - 1] * qnt;
        }
      } while (np != 0 || np < 0 || np > 5);
      printf("\n");
    }
  }
  printf("\n\n");
  printMatrix(distinte);
}

void printMatrix(const double distinte[AGENTS][COLUMNS][ELEMENTS]) {
  for (int i = 0; i < 4; i++)
    for (int k = 0; k < 5; k++)
      if (distinte[i][1][k] > 0)
        printf("Agnt: %d\nPrd %d\nQnt: %d\nTot: %.2lf\n\n\n", i + 1, k + 1,
               (int)(distinte[i][1][k] / distinte[i][0][k]), distinte[i][1][k]);
}
