// Scrivere un programma in C che simuli un GDR
// 2 Giocatori [100 HP]
// Attraverso la libreria stdlib e time utilizzare srand e rand per simulare 3
// turni di attacco per un giocatore Ogni turno verra' lanciato un dado da 20,
// il risultato del lancio corrispondera' ai danni inflitti all'avversario Nel
// caso in cui il lancio del dado dia come risultato 20 si avra' un danno
// raddoppiato
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);

int main(void) {
  srand(time(NULL));
  int p1 = 100;
  int p2 = 100;

  for (int i = 1; p1 > 0 || p2 > 0; i++) {
    printf("%d Turno!\nPlayer 1: %d HP\tPlayer 2: %d HP\n\n", i, p1, p2);

    int dmg = rollDice();

    if (dmg == 20) {
      printf("COLPO CRITICO!!!\n");
      dmg *= 2;
    }

    if ((i % 2) != 0) {
      p2 -= dmg;
      printf("Giocatore 1, hai totalizzato %d\n\n", dmg);
      printf("Gli hp del giocatore 2 ridotti a: %d\n\n\n\n", p2 > 0 ? p2 : 0);
    } else {
      p1 -= dmg;
      printf("Giocatore 2, hai totalizzato %d\n\n", dmg);
      printf("Gli hp del giocatore 1 ridotti a: %d\n\n\n\n", p1 > 0 ? p1 : 0);
    }

    if (p1 <= 0) {
      printf("Giocatore 1 sei stato ucciso!\nLa vittoria va a giocatore 2");
      break;
    }

    if (p2 <= 0) {
      printf("Giocatore 2 sei stato ucciso!\nLa vittoria va a giocatore 1");
      break;
    }
  }
}

int rollDice(void) { return 1 + rand() % 20; }
