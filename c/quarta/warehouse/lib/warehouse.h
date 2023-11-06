#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#define MAX_PRODUCTS 100
#define BUFFER 32

typedef struct {
    char name[BUFFER];
    double price;
    unsigned int quantity;
    unsigned int ID;
} Product;

typedef struct {
    Product products[MAX_PRODUCTS];
    unsigned int size;
} Warehouse;

void print_menu (void);
void print_products (Warehouse *warehouse);
void add_product (Warehouse *warehouse);
void remove_product (Warehouse *warehouse);
void add_quantity (Warehouse *warehouse);
void remove_quantity (Warehouse *warehouse);
void print_total_value (Warehouse *warehouse);
void print_order (Warehouse *warehouse);
void save_warehouse (Warehouse *warehouse);
void load_warehouse (Warehouse *warehouse);

#endif
