#include <stdio.h>

double average(double *px, double *py, double *pz);

int main(void) {
  double x, y, z;

  puts("Insert x value: ");
  scanf("%lf", &x);

  puts("Insert y value: ");
  scanf("%lf", &y);

  puts("Insert z value: ");
  scanf("%lf", &z);

  printf("Average for the three values is: %.2lf\n\n", average(&x, &y, &z));
}

double average(double *px, double *py, double *pz) {
  return (*px + *py + *pz) / 3;
}

