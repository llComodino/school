#include <stdio.h>

#define ROWS 14
#define COLS 8
#define BUF 5

void print_info(void);
void print_seats(const int[][COLS]);
int assign_seat(int[][COLS], char[]);
void print_ticket(char[]);
void clear(void);

int main(void) {
  int seats[ROWS][COLS] = {0};

  for (int i = 0; i < ROWS * COLS; i++) {
    char seat[BUF];
    printf("Customer %d\n\n", i + 1);
    print_info();
    print_seats(seats);

    int chk = assign_seat(seats, seat);

    while (chk == 2) {
      chk = assign_seat(seats, seat);
      if (chk) {
        continue;
      }
    }

    if (chk == 3) {
      return 1;
    }

    print_ticket(seat);

    puts("Press enter to continue ...");

    char s = getchar();
    while ((s = getchar()) != '\n')
      ;

    printf("\n\n\n");
  }
  return 0;
}

void print_info(void) {
  puts("Hello dear customer, welcome to NoxusPlex!");
  puts("As of today we stream only one (but really good!) movie");
  puts("would you like to purchase a ticket in one the aviable seats?");
}

void print_seats(const int seats[][COLS]) {
  printf("\n    ");
  for (int i = 0; i < COLS; i++) {
    printf("%2d", i + 1);
  }

  for (int i = 0; i < ROWS; i++) {
    printf("\n%c > ", i + 65);
    for (int j = 0; j < COLS; j++) {
      printf("%2s", seats[i][j] == 0 ? "-" : "X");
    }
  }
  printf("\n");
}

int assign_seat(int seats[][COLS], char seat[]) {
  puts("Insert the seat like shown 'A4' - [0 to terminate]");
  scanf("%s", seat);

  for (int i = 0; seat[i] != '\0'; i++) {
    if (i > 1) {
      puts("The specified seat does not exist!");
      return 2;
    }
  }

  if (seat[0] == '0') {
    return 3;
  }

  int row;

  if (seat[1] > '0' && seat[1] < '9') {
    if (seat[0] >= 'a' && seat[0] <= 'a' + ROWS - 1) {
      row = seat[0] - 103;
      seat[0] -= 32;
    } else if (seat[0] >= 'A' && seat[0] <= 'A' + ROWS - 1) {
      row = seat[0] - 71;
    } else {
      puts("The specified seat does not exist!");
      return 2;
    }
  } else {
    puts("The specified seat does not exist!");
    return 2;
  }

  if (seats[row][seat[1] - 1]) {
    char chr;
    printf("Seat already taken, would you try with a new one? (y/n) > ");

    do {
      scanf("%s", &chr);
    } while (chr != 'y' && chr != 'Y' && chr != 'n' && chr != 'N');

    if (chr == 'y' || chr == 'Y') {
      return 2;
    }
    return 1;
  }

  seats[row][seat[1] - 1] = 1;

  return 0;
}

void print_ticket(char seat[]) {
  printf("==============================\n");
  printf("| %26s |\n", "NoxusPlex");
  printf("| %26s |\n", "Katarina's Chronicles");
  printf("| %26s |\n", "20:45");
  printf("| %26s |\n", seat);
  printf("==============================\n");
}

