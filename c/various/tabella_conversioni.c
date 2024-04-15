// Diego Gila       3Ein
//
// Scrivere un programma che stampi a schermo la seguente tablla per i numeri da
// 1 a 256 Decimale:        Binario:        Ottale:     Esadecimale:
#include <stdio.h>

int binconv(int n); //----------------------//
int ottconv(int n); //  Prototipi funzioni  //

int main() {
  printf("%9s%15s%15s%20s\n", "Decimale:", "Binario:", "Ottale:",
         "Esadecimale:"); // Tabella con spazi giustificti
  for (int i = 1; i <= 256; i++)
    printf("%9d%15d%15d%20.1X\n", i, binconv(i), ottconv(i), i);
  return 0;
}

int binconv(int n) {
  int rem;
  int binary = 0;
  // Converto da decimale a binario
  for (int temp = 1; n != 0; temp *= 10) {
    rem = n % 2;
    n /= 2;
    binary += rem * temp;
  }
  return binary;
}

int ottconv(int n) {
  int oct = 0;
  // Converto da decimale a ottale
  for (int i = 1; n != 0; i *= 10) {
    oct += (n % 8) * i;
    n /= 8;
  }
  return oct;
}