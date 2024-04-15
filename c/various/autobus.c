// Siete titolari di una piccola azienda di trasporti
// Disponete di un solo bus
// Questo autobus fa soltanto 3 tratte
// Il biglietto di ogni tratta differisce da quello precedente di .75 $
// L'autobus ha una capienza di 20 posti a sedere e 10 posti in piedi
// Utilizzate 2 vettori per assegnare i posti a sedere e quelli in piedi
// Quando un passeggero si presentera' alla porta il conducente gli dovra'
// chiedere la destinazione Esigere il pagamento e consegnare il titolo di
// viaggio: Meta Costo Nome Ditta
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_S 10
#define SIZE_P 5
#define BUFFER 10

void printMete(const double[]);
void printTicket(const double[], int, int);
int aviableSeats(const int[]);

int main(void) {
  char mete[3][BUFFER] = {{"Ionia"}, {"Noxus"}, {"Piltover"}};
  double prices[3] = {3.5, 4.25, 5};
  int choices[SIZE_S + SIZE_P] = {0};

  // Chiedo all'utente la destinazione desiderata
  for (int i = 1; i < 4; i++) {
    if (i == 0)
      printf("Stazione di partenza\n\n");

    else
      printf("%s\n\n", mete[i - 1]);
    int c = 0;
    for (int k = 0; k < SIZE_S + SIZE_P && i != 1; k++)
      if (choices[k] == i - 2) {
        choices[k] = 0;
        c++;
      }

    printf("Si sono liberati %d posti!\n", c);

    for (int j = 0; j < aviableSeats(choices); j++) {
      printf("Ci sono attualmente %d posti disponibili\n\n",
             aviableSeats(choices));
      do {

        printf("Cliente %d, dove desideri andare?\n", j + 1);
        printMete(prices); // Stampo le varie mete
        printf("> ");
        scanf("%d", &choices[j]);
        if (choices[j] == 0)
          break;

      } while (choices[j] < 0 || choices[j] > 3 || choices[j] == i);

      if (choices[j] == 0)
        break;

      else {
        system("cls");
        printTicket(prices, choices[j], j);
        printf("\nPremi per continuare ... ");
        getch();
        system("cls");
      }
    }
  }
  return 0;
}

void printMete(const double prices[]) {
  char mete[3][BUFFER] = {{"Ionia"}, {"Noxus"}, {"Piltover"}};

  printf("\nMete:\n");

  for (int i = 0; i < 3; i++)
    printf("%d.%9s%6.2f $\n", i + 1, mete[i], prices[i]);

  printf("-------------------\n0.%9s\n", "Exit");
}

void printTicket(const double prices[], int choice, int pos) {
  char mete[3][BUFFER] = {{"Ionia"}, {"Noxus"}, {"Piltover"}};

  printf("\n\n%22s\n", "**********************");
  printf("* %9s%9d *\n", "Cliente:", pos + 1);
  printf("* %9s%9s *\n", "Meta:", mete[choice - 1]);
  printf("* %9s%9s *\n", "Posto:", pos < SIZE_S ? "A Sedere" : "In Piedi");
  printf("* %9s%9.2f *\n", "Totale:", prices[choice - 1]);
  printf("%22s\n", "**********************");
}

int aviableSeats(const int choices[]) {
  int as = 0;
  for (int i = 0; i < SIZE_P + SIZE_S; i++)
    if (choices[i] == 0)
      as++;

  return as;
}
