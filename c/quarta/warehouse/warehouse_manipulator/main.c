/*
 * Create un sistema di gestione di un magazzino che consenta di:
 * - Aggiungere o rimuovere delle quantita
 * - Tenere traccia delle quantità stesse
 * - Gestire gli ordini dei clienti
 * - Calcolare il valore totale delle scorte
 *
 * Il vostro programma dovra' essere in grado di gestire i prodotti con i seguenti attributi:
 * - nome
 * - prezzo
 * - quantità disponibile
 * - codice prodotto
 *
 * Una volta terminato create un file con le rimanenze del magazzino
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/warehouse.h"

int main (void) {
    
    Warehouse warehouse;
    warehouse.size = 0;

    load_warehouse(&warehouse);

    int choice = 0;
    do {
        
        print_menu();
        
        do {
            scanf("%d", &choice);
        } while (choice < 0 || choice > 9);

        switch (choice) {
        
            case 1:
                print_products(&warehouse);
                break;
            
            case 2:
                add_product(&warehouse);
                break;
            
            case 3:
                remove_product(&warehouse);
                break;
            
            case 4:
                add_quantity(&warehouse);
                break;
            
            case 5:
                remove_quantity(&warehouse);
                break;
            
            case 6:
                print_total_value(&warehouse);
                break;
            
            case 7:
                print_order(&warehouse);
                break;
            
            case 8:
                save_warehouse(&warehouse);
                break;
            
            case 9:
                load_warehouse(&warehouse);
                break;
            
            case 0:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void print_menu (void) {
    
    puts("1. Print products\n");
    puts("2. Add product\n");
    puts("3. Remove product\n");
    puts("4. Add quantity\n");
    puts("5. Remove quantity\n");
    puts("6. Print total value\n");
    puts("7. Print order\n");
    puts("8. Save warehouse\n");
    puts("9. Load warehouse\n");
    puts("0. Exit\n");
    printf("Choice: ");

    return;
}

void add_product (Warehouse *warehouse) {
    
    if (warehouse->size == MAX_PRODUCTS) {
        puts("Warehouse is full!\n\n");
        return;
    }

    getchar();
    printf("Insert product name: ");
    fgets(warehouse->products[warehouse->size].name, BUFFER, stdin);
    warehouse->products[warehouse->size].name[strlen(warehouse->products[warehouse->size].name) - 1] = '\0';

    printf("Insert product price: ");
    scanf("%lf", &warehouse->products[warehouse->size].price);
    
    printf("Insert product quantity: ");
    scanf("%d", &warehouse->products[warehouse->size].quantity);

    warehouse->products[warehouse->size].ID = warehouse->size + 1;
    
    warehouse->size++;

    puts("\n");

    return;
}

void remove_product (Warehouse *warehouse) {
    
    void shift_ID(Warehouse *warehouse, unsigned int index);
    
    int ID = 0;
    
    printf("Insert product ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < warehouse->size; i++) {
        
        if (warehouse->products[i].ID == ID) {
        
            for (int j = i; j < warehouse->size - 1; j++) {
                warehouse->products[j] = warehouse->products[j + 1];
            }
            
            shift_ID(warehouse, i);
            warehouse->size--;
            return;
        }
    }

    printf("Product not found!\n");

    return;
}

void shift_ID (Warehouse *warehouse, unsigned int index) {
    
    for (int i = index; i < warehouse->size; i++) {
        warehouse->products[i].ID--;
    }

    return;
}

void add_quantity (Warehouse *warehouse) {
    int ID = 0;
    printf("Insert product ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].ID == ID) {
            printf("Insert quantity to add: ");
            scanf("%d", &ID);
            warehouse->products[i].quantity += ID;
            return;
        }
    }

    printf("Product not found!\n");

    return;
}

void remove_quantity (Warehouse *warehouse) {
    int ID = 0;
    printf("Insert product ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].ID == ID) {
            printf("Insert quantity to remove: ");
            scanf("%d", &ID);
            warehouse->products[i].quantity -= ID;
            return;
        }
    }

    printf("Product not found!\n");

    return;
}

void print_total_value (Warehouse *warehouse) {
    double total = 0;
    for (int i = 0; i < warehouse->size; i++) {
        total += warehouse->products[i].price * warehouse->products[i].quantity;
    }

    printf("Total value: %.2lf\n", total);

    return;
}

void print_order (Warehouse *warehouse) {
    int ID = 0;
    printf("Insert product ID: ");
    scanf("%d", &ID);

    for (int i = 0; i < warehouse->size; i++) {
        if (warehouse->products[i].ID == ID) {
            printf("Product: %s\n", warehouse->products[i].name);
            printf("Price: %.2lf\n", warehouse->products[i].price);
            printf("Quantity: %d\n", warehouse->products[i].quantity);
            printf("Total: %.2lf\n", warehouse->products[i].price * warehouse->products[i].quantity);
            return;
        }
    }

    printf("Product not found!\n");

    return;
}
