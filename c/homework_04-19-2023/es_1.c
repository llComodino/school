#include <stdio.h>

int calculate(const int (*operation)(const int *const, const int *const));
// Arithmetical Operations
int sum(const int *const, const int *const);
int dif(const int *const, const int *const);
int mol(const int *const, const int *const);
int div(const int *const, const int *const);

int main(void) {
  int tot;

  puts("1. Sum\n2. Dif\n3. Mol\n4. Div");

  char op;
  do {
    scanf("%c", &op);
  } while (op < '1' || op > '4');

  switch (op) {

  case '1':
    tot = calculate(sum);
    break;

  case '2':
    tot = calculate(dif);
    break;

  case '3':
    tot = calculate(mol);
    break;

  case '4':
    tot = calculate(div);
    break;

  default:
    puts("How did you even do it?!");
    return 1;
    break;
  }

  printf("\nResult is: %d\n", tot);
  return 0;
}

int calculate(const int (*operation)(const int *const, const int *const)) {
  int n1, n2;
  puts("\nInsert 2 integers");
  scanf("%d%d", &n1, &n2);

  return ((*operation)(&n1, &n2));
}

int sum(const int *const pn1, const int *const pn2) { return *pn1 + *pn2; }

int dif(const int *const pn1, const int *const pn2) { return *pn1 - *pn2; }

int mol(const int *const pn1, const int *const pn2) { return (*pn1) * (*pn2); }

int div(const int *const pn1, const int *const pn2) { return *pn1 / *pn2; }
