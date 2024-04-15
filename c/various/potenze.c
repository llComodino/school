// Utilizzando la libreria math.h calolare e stampare in modo ordinato uno
// schema equidistante dall'inizio che riporti come intestazione numero '6
// spazi' quadrato '6 spazi' cubo 'newline' Il programma dovra' calcolare e
// mostrare nella prima colonn i numeri da 0 a 10 Nella seconda colonna i
// quadrati da 0 a 100 Nella terza i cubi da 0 a 1000
#include <math.h>
#include <stdio.h>

int main() {
  printf("%6s%12s%10s\n", "Numero:", "Quadrato:", "Cubo:");
  for (int i = 0; i <= 10; i++)
    printf("%6d%12.0f%10.0f\n", i, pow(i, 2), pow(i, 3));
}