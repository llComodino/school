#include "../lib/customers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  Warehouse *warehouse = malloc(sizeof(Warehouse));
  load_warehouse(warehouse);

  Customer *customer = create_customer();
  customer->order_count = 0;
  customer->order = malloc(sizeof(Order) * MAX_ORDERS);

  print_customer(customer);

  char answer;
  for (size_t i = 0; i < MAX_ORDERS; i++) {

    puts("Make a new order ? (y/n) : ");
    do {
      scanf("%c", &answer);
    } while (answer != 'y' && answer != 'n');

    if (answer == 'n') {
      break;
    }

    customer->order_count++;
    customer->order[i].product = malloc(sizeof(Product));
    customer->order[i] = add_order(warehouse);
  }

  puts("\n");

  print_customer_orders(customer);

  free_customer(customer);
  free(warehouse);

  return 0;
}

Customer *create_customer() {

  Customer *customer = malloc(sizeof(Customer));

  // Create a new customer
  printf("Enter your full name: ");
  fgets(customer->name, BUFFER, stdin);
  customer->name[strlen(customer->name) - 1] = '\0';

  printf("Enter your address: ");
  fgets(customer->address, BUFFER, stdin);
  customer->address[strlen(customer->address) - 1] = '\0';

  printf("Enter your email: ");
  fgets(customer->email, BUFFER, stdin);
  customer->email[strlen(customer->email) - 1] = '\0';

  printf("Enter your phone: ");
  fgets(customer->phone, BUFFER, stdin);
  customer->phone[strlen(customer->phone) - 1] = '\0';

  return customer;
}

void print_customer(Customer *customer) {

  printf("Customer: %s\n", customer->name);
  printf("Address: %s\n", customer->address);
  printf("Email: %s\n", customer->email);
  printf("Phone: %s\n", customer->phone);

  return;
}

Order add_order(Warehouse *warehouse) {

  Order order;
  order.product = malloc(sizeof(Product));

  print_products(warehouse);

  do {
    printf("Enter the product ID: ");
    scanf("%d", &order.product->ID);
  } while (order.product->ID < 1 || order.product->ID > warehouse->size ||
           warehouse->products[order.product->ID - 1].quantity == 0);

  do {
    printf("Enter the quantity: ");
    scanf("%d", &order.quantity);
  } while (order.quantity < 1 ||
           order.quantity >
               warehouse->products[order.product->ID - 1].quantity);

  order.product->price = warehouse->products[order.product->ID - 1].price;
  strcpy(order.product->name, warehouse->products[order.product->ID - 1].name);

  update_warehouse(warehouse, &order);
  save_warehouse(warehouse);
  load_warehouse(warehouse);

  return order;
}

void print_customer_orders(Customer *customer) {

  printf("Orders:\n");
  for (size_t i = 0; i < customer->order_count; i++) {

    printf("Product: %s\n", customer->order[i].product->name);
    printf("Quantity: %d\n", customer->order[i].quantity);
    printf("Price: %.2f x %d\n", customer->order[i].product->price,
           customer->order[i].quantity);
    printf("Total: %.2f\n",
           customer->order[i].product->price * customer->order[i].quantity);

    puts("\n--------------------------\n");
  }

  return;
}

void free_customer(Customer *customer) {

  for (size_t i = 0; i < customer->order_count; i++) {
    free(customer->order[i].product);
  }

  free(customer->order);
  free(customer);

  return;
}

void update_warehouse(Warehouse *warehouse, Order *order) {

  warehouse->products[order->product->ID - 1].quantity -= order->quantity;

  return;
}
