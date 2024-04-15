#include <stdio.h>
#include <string.h>

double power(double, double);
double todouble(char *);

int main(int argc, char **argv) {

  double sum = 0;

  for (size_t i = 1; i < argc; i++) {

    sum += todouble(*(argv + i));
  }

  printf("%.2f\n", sum);

  return 0;
}

double power(double base, double exp) {

  if (exp == 0) {

    return 1;
  }

  for (size_t i = 1; i < exp; i++) {

    base *= base;
  }

  return base;
}

double todouble(char *number) {

  double num = 0;
  double tmp = 0;

  for (size_t i = 0; i < strlen(number); i++) {

    tmp = ((double)(*(number + i)) - 48);
    num += (tmp * power(10, strlen(number) - i - 1));
  }

  return num;
}

