// Un giocatore lancia 2 dadi, ognuno a 6 facce
// Se la somma delle facce fosse 7 o 11 al primo tiro il giocatore avrebbe vinto
// Nel caso fosse 2,3 o 12 al primo tiro avrebbe perso
// Nel caso fosse 4,5,6,8,9 o 10 al primo tiro questo sarebbe il punteggio del
// giocatore Per vincere bisogna pareggiare il punteggio con un ulteriore lancio
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { WON, LOST, CONTINUE };

int rollDice(void);

int main() {
  int sum, mypoint;
  enum Status gameStatus;

  srand(time(NULL));

  sum = rollDice();

  switch (sum) {
  case 7:
  case 11:
  case 19:
  case 21:
    gameStatus = WON;
    break;

  case 2:
  case 3:
  case 12:
  case 20:
    gameStatus = LOST;
    break;

  default:
    gameStatus = CONTINUE;
    mypoint = sum;
    break;
  }
  while (gameStatus == CONTINUE) {
    sum = rollDice();

    if (sum == mypoint)
      gameStatus = WON;

    else if (sum == 7 || sum == 21)
      gameStatus = LOST;
  }
  if (gameStatus == WON)
    printf("Player won\n");

  else
    printf("PLayer Lost\n");

  return 0;
}

int rollDice(void) {
  int dice1 = 1 + rand() % 6;
  int dice2 = 1 + rand() % 6;
  int diceSum = dice1 + dice2;

  printf("Player scored %d + %d = %d\n", dice1, dice2, diceSum);

  return diceSum;
}
