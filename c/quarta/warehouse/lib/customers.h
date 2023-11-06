#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include "warehouse.h"

#define MAX_ORDERS 10

typedef struct {
    Product *product;
    int quantity;
} Order;

typedef struct {
    char name[BUFFER];
    char address[BUFFER];
    char email[BUFFER];
    char phone[BUFFER];
    Order *order;
    unsigned int order_count;
} Customer;

Customer * create_customer (void);
Order add_order (Warehouse *warehouse);
void print_customer (Customer *customer);
void print_customer_orders (Customer *customer);
void free_customer (Customer *customer);

#endif
