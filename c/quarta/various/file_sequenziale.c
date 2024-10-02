#include <stdio.h>

int main(void) {

  FILE *file = NULL;

  if ((file = fopen("file_sequenziale.txt", "w")) == NULL) {
    printf("Errore nell'apertura del file\n");
    return 1;
  }

  unsigned int account;
  char nome[30];
  double saldo;

  printf("Inserisci il numero di conto, il nome e il saldo\n");
  printf("Inserisci EOF per terminare l'input\n");
  printf("? ");

  while (scanf("%d%s%lf", &account, nome, &saldo) != EOF) {
    fprintf(file, "%d %s %.2f\n", account, nome, saldo);
    printf("? ");
  }

  fclose(file);
  return 0;
}

