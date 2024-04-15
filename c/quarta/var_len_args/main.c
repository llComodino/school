#include <stdarg.h>
#include <stdio.h>

double avg(int i, ...);

int main(void) {

  double n1 = 2;
  double n2 = 4;
  double n3 = 6;
  double n4 = 8;

  printf("Avg is: %.2f\n", avg(4, n1, n2, n3, n4));

  return 0;
}

double avg(int i, ...) {

  double avg = 0;
  va_list arg_list;

  va_start(arg_list, i);

  for (size_t idx = 0; (int)(idx) < i; idx++) {

    avg += va_arg(arg_list, double);
  }

  va_end(arg_list);

  return (avg / i);
}
