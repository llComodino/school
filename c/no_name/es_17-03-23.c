// Utilizzando un vettore ad una dimensione N = 10 simulare per ogni locazione
// di memoria un ordine fatto in un negozio di videogame Il negozio vendera'
// soltanto i seguenti articoli
// 1. Gioco PS5 $ 79.99
// 2. Cuffie wireless $ 55.00
// 3. Joypad $ 49.99
// 4. Abbonamento online trimestrale $ 25.00
// 5. Gioco nintendo-switch $ 59.99
// Per ogni ordine dovrete stampare il relativo scontrino con:
// - Nome del negozio
// - Numero di articoli
// - Quantita' per ogni articolo
// - Totale
// - Metodo di pagamento utilizzato
// - Eventuale resto in caso di pagamento in contanti
#include <stdio.h>
#include <stdlib.h>

#define PRD 5
#define SIZE 10
#define BUF 32

void print_prd(const char[][BUF], const double[SIZE]);
int order(double[SIZE], const char[][BUF]);
void print_tot(const double[SIZE], const char[][BUF]);

int main(void) {
  double prd_prices[SIZE] = {79.99, 55, 49.99, 25, 59.99};
  char prd_names[PRD][BUF] = {{"PS5 Game"},
                              {"Wireless Headphones"},
                              {"Joypad"},
                              {"Trimestral online subscription"},
                              {"Nintendo-Switch Game"}};

  for (int i = 0; i < SIZE; i++) {
    print_prd(prd_names, prd_prices);
    if (order(prd_prices, prd_names)) {
      return 1;
    }
  }
  return 0;
}

void print_prd(const char prd_names[][BUF], const double prd_prices[PRD]) {
  printf("Welcome to RiftStop!\nHere we sell all kinds of overpriced "
         "articles!\n\nHave a look around!\n\n");
  for (int i = 0; i < PRD; i++) {
    printf("%d.%32s%6.2lf $\n", i + 1, prd_names[i], prd_prices[i]);
  }
  printf("\n");
}

int order(double prd_prices[PRD], const char prd_names[][BUF]) {
  int prd;
  int qnt;
  char sen = 'y';

  while (sen == 'y' || sen == 'Y') {
    printf("What would you like to purchase? [0 per terminare] > ");

    do {
      scanf("%d", &prd);
    } while (prd < 0 || prd > 5);

    if (prd == 0) {
      return 1;
    }

    printf("How many? > ");

    do {
      scanf("%d", &qnt);
    } while (qnt < 0);

    prd_prices[prd + 4] += prd_prices[prd - 1] * qnt;

    printf("Would you like to purchase something else? [y]es [n]o > ");

    do {
      scanf("%s", &sen);
    } while (sen != 'y' && sen != 'Y' && sen != 'n' && sen != 'N');

    if (sen == 'n' || sen == 'N') {
      break;
    }
  }
  print_tot(prd_prices, prd_names);
  return 0;
}

void print_tot(const double prd_prices[PRD], const char prd_names[][BUF]) {
  int sel;
  double cont;
  double tot = 0;

  for (int i = PRD; i < SIZE; i++) {
    tot += prd_prices[i];
  }

  printf("\n\nHow would you like to pay?\n1. Card\n2. Cash\n> ");
  do {
    scanf("%d", &sel);
  } while (sel < 1 || sel > 2);

  if (sel == 2) {
    printf("Cash (tot: %6.2lf) > ", tot);

    do {
      scanf("%lf", &cont);
    } while (cont < tot);
  }

  printf("\n%47s\n", "***********************************************");
  printf("* RiftStop%37s\n", "*");
  for (int i = PRD; i < SIZE; i++) {
    if (prd_prices[i] != 0) {
      printf("*%3.0lfx%32s%6.2lf $ *\n",
             (int)prd_prices[i] / prd_prices[i - PRD], prd_names[i - PRD],
             prd_prices[i - PRD]);
    }
  }
  printf("* Tot :%10.2lf $%28s\n", tot, "*");
  if (sel == 2) {
    printf("* Cash:%10.2lf $%28s\n* Rest:%10.2lf $%28s\n", cont, "*",
           cont - tot, "*");
  }
  printf("%47s\n\n", "***********************************************");
}

