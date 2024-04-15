// Date 3 stringhe di dimensione SIZE calcolare il quadrato degli elementi del
// primo diviso gli elementi del terzo Successivamente summare gli elementi del
// secondo
#include <math.h>
#include <stdio.h>

#define SIZE 10

void calc(char str1[], char str2[], char str3[]);

int main(void) {
  char str1[SIZE] = "abcdefghij";
  char str2[SIZE] = "ajdeoritug";
  char str3[SIZE] = "ndlgkeushe";

  calc(str1, str2, str3);
}

void calc(char str1[], char str2[], char str3[]) {
  for (int i = 0; i < SIZE; i++) {
    float tot = pow(str1[i], 2) / str3[i] + str2[i];
    printf("%c = %d\t%c = %d\t%c = %d\n%d^2 / %d + %d = %.2f\n\n", str1[i],
           str1[i], str2[i], str2[i], str3[i], str3[i], str1[i], str3[i],
           str2[i], tot);
  }
}