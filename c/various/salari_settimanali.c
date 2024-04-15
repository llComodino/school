// Diego Gila       3Ein
#include <stdio.h>

int main() {
  int n, role, h, s, ricavo, prodotti;
  printf("Inserire il numero di dipendenti: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("\nInserire il codice di pagamento del dipendente %d: ", i);
    scanf("%d", &role);

    switch (role) {
    case 1:
      printf("%8d", 2000);
      break;
    case 2:
      printf("Inserire il numero di ore lavorative e di straordinari: ");
      scanf("%d%d", &h, &s);
      printf("%8.2f", h * 40 + s * 40 * 1.5);
      break;
    case 3:
      printf(
          "Inserire il ricavo lordo delle vendite della settimana corrente: ");
      scanf("%8d", &ricavo);
      printf("%8.2f", 250 + ricavo * 0.057);
      break;
    case 4:
      printf("Inserire il numero di articoli prodotti: ");
      scanf("%d", &prodotti);
      printf("%8d", prodotti * 20);
      break;
    default:
      printf("Codice prodotto non esistente, inserirne uno valido\n\n");
      i--;
      break;
    }
  }
}