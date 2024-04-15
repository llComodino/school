// Diego Gila           3Ein
#include <stdio.h>

void hanoi(int disks, char pioloPartenza, char pioloArrivo,
           char pioloAusiliario);

int main(void) {
  int n;
  printf("Inserire il numero di dischi: ");
  scanf("%d", &n);

  hanoi(n, '1', '3', '2');

  return 0;
}

void hanoi(int disks, char pioloPartenza, char pioloArrivo,
           char pioloAusiliario) {
  if (disks == 1)
    printf("%c --> %c\n", pioloPartenza, pioloArrivo);

  else {
    hanoi(disks - 1, pioloPartenza, pioloAusiliario, pioloArrivo);

    printf("%c --> %c\n", pioloPartenza, pioloArrivo);

    hanoi(disks - 1, pioloAusiliario, pioloArrivo, pioloPartenza);
  }
}
