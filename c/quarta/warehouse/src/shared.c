#include "../lib/customers.h"
#include "../lib/warehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_products(Warehouse *warehouse) {

  puts("Products:\n");

  for (int i = 0; i < warehouse->size; i++) {

    printf("ID: %d\n%s\n%.2lf $\nAviable Stock: %d\n\n",
           warehouse->products[i].ID, warehouse->products[i].name,
           warehouse->products[i].price, warehouse->products[i].quantity);

    puts("---------------\n");
  }

  puts("\n");

  return;
}

void load_warehouse(Warehouse *warehouse) {

  FILE *fp = fopen("warehouse.dat", "rb");

  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  warehouse->size = 0;

  while (fread(&warehouse->products[warehouse->size], sizeof(Product), 1, fp) ==
         1) {
    warehouse->size++;
  }

  fclose(fp);

  return;
}

void save_warehouse(Warehouse *warehouse) {
  FILE *fp = fopen("warehouse.dat", "wb");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  for (int i = 0; i < warehouse->size; i++) {
    fwrite(&warehouse->products[i], sizeof(Product), 1, fp);
  }

  fclose(fp);

  return;
}
