// Diego Gila       3Ein
#include <math.h>
#include <stdio.h>

double ipo(double x, double y);

int main(void) {
  double lato1, lato2;

  printf("Inserire la lunghezza del lato 1: ");
  scanf("%lf", &lato1);

  printf("Inserire la lunghezza del lato 2: ");
  scanf("%lf", &lato2);

  printf("L'ipotenusa vale: %f", ipo(lato2, lato1));
  return 0;
}

double ipo(double x, double y) {
  double tot = pow(x, 2) + pow(y, 2);
  return sqrt(tot);
}