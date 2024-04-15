#include <stdio.h>
#include <stdlib.h>

#define FUNCTIONS 3

void print_menu(void);
void circle_circ(void);
void circle_area(void);
void sphere_volume(void);

int main(void) {

  int choice;

  while (1) {

    print_menu();

    do {
      scanf("%d", &choice);
    } while (choice < 0 || choice > 3);

    // Array of pointers to functions
    void (*func_ptr[FUNCTIONS])(void) = {circle_circ, circle_area,
                                         sphere_volume};

    if (choice == 3) {
      puts("Terminate program...");
      break;
    }

    func_ptr[choice]();
  }
  return 0;
}

void print_menu(void) {

  printf("0. Circle circumference\n");
  printf("1. Circle area\n");
  printf("2. Sphere volume\n");
  printf("3. Terminate program\n");
  printf("Insert choice: ");

  return;
}

void circle_circ(void) {

  double radius;
  printf("Insert radius: ");
  scanf("%lf", &radius);

  printf("\n\nCircumference radius: %.2f\n", radius);
  printf("Circumference: %.2f\n\n\n", 2 * 3.14 * radius);

  return;
}

void circle_area(void) {

  double radius;
  printf("Insert radius: ");
  scanf("%lf", &radius);

  printf("\n\nArea radius: %.2f\n", radius);
  printf("Area: %.2f\n\n\n", 3.14 * radius * radius);

  return;
}

void sphere_volume(void) {

  double radius;
  printf("Insert radius: ");
  scanf("%lf", &radius);

  printf("\n\nSphere radius: %.2f\n", radius);
  printf("Sphere volume: %.2f\n\n\n",
         4.0 / 3.0 * 3.14 * radius * radius * radius);

  return;
}
