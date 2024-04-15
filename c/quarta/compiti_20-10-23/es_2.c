#include <stdbool.h>
#include <stdio.h>

#define FUN 3

double bike_emission(void);
double car_emission(void);
double warehouse_emission(void);

int main(void) {

  double (*fnptr[FUN])(void) = {bike_emission, car_emission,
                                warehouse_emission};

  while (true) {

    int choice;
    printf("1. Bike\n2. Car\n3. Warehouse\n4. Exit\n");

    do {
      scanf("%d", &choice);
    } while (choice < 1 || choice > 4);

    if (choice == 4) {
      break;
    }

    printf("Emission: %.2f km\n\n\n", fnptr[choice - 1]());
  }

  return 0;
}

double bike_emission(void) {

  // Le bici non emettono CO2
  puts("Bikes don't emit CO2");
  return 0;
}

double car_emission(void) {

  // Per calcolare le emissioni di co2
  // di un'auto si moltiplica il g/km
  // per il numero di km percorsi
  double km, g;
  printf("Insert km: ");

  do {
    scanf("%lf", &km);
  } while (km < 0);

  printf("Insert g/km: ");

  do {
    scanf("%lf", &g);
  } while (g < 0);

  return km * g;
}

double warehouse_emission(void) {

  // Per calcolare le emissioni di CO2
  // di un magazzino si moltiplica il
  // consumo energetico per il g/km
  double e, g;
  printf("Insert energy consumption [kW]: ");

  do {
    scanf("%lf", &e);
  } while (e < 0);

  printf("Insert g/km: ");

  do {
    scanf("%lf", &g);
  } while (g < 0);

  return e * g;
}
