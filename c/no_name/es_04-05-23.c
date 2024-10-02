#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define POKER_HAND 5
#define HANDS 2

void shuffle(unsigned int[][FACES]);
void deal(unsigned int[][FACES], const char *const[], const char *const[],
          const int, int *const);
void pairs(const int *const, int *const);
void colour(const unsigned int[][FACES], int *const, const int);
void straight(const int *const, int *const);
void better(const int *const);

// debug
void print_deck(const unsigned int[][FACES]);
void print_dealt(const int *const);

int main(void) {

  unsigned int deck[SUITS][FACES] = {0};
  int hands[HANDS] = {0};

  srand(time(NULL));

  shuffle(deck);

  const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  const char *face[FACES] = {"Ace",  "Two",   "Three", "Four", "Five",
                             "Six",  "Seven", "Eight", "Nine", "Ten",
                             "Jack", "Queen", "King"};

  for (int i = 0; i < HANDS; i++) {

    int dealt[FACES] = {0};
    deal(deck, face, suit, i, dealt);

    print_dealt(dealt);
    // print_deck(deck);

    // Check for combinations
    pairs(dealt, &hands[i]);
    colour(deck, &hands[i], i);
    straight(dealt, &hands[i]);

    puts("");
  }

  better(hands);
  return 0;
}

void shuffle(unsigned int deck[][FACES]) {

  for (size_t card = 1; card <= CARDS; card++) {
    size_t row, col;

    do {
      row = rand() % SUITS;
      col = rand() % FACES;
    } while (deck[row][col] != 0);

    deck[row][col] = card;
  }
  return;
}

void deal(unsigned int deck[][FACES], const char *const face[],
          const char *const suit[], const int hand, int *const pdealt) {

  for (size_t card = 1, dealt = 0; dealt < POKER_HAND; card++) {
    for (size_t row = 0; row < SUITS; row++) {
      for (size_t col = 0; col < FACES; col++) {
        if (deck[row][col] == card) {
          deck[row][col] = -hand;
          dealt++;
          *(pdealt + col) += 1;
          printf("%5s of %-8s\n", face[col], suit[row]);
        }
      }
    }
  }
  puts("");
  return;
}

void pairs(const int *const dealt, int *const current) {

  int pairs = 0;
  int tris = 0;

  for (size_t i = 0; i < FACES; i++) {
    if (*(dealt + i) == 2) {
      pairs++;
    } else if (*(dealt + i) == 3) {
      tris++;
    } else if (*(dealt + i) == 4) {
      puts("Four of a kind!");
      *current += 7;
      return;
    }
  }

  if (pairs == 2) {
    puts("Two Pair!");
    *current += 2;
  } else if (pairs == 1 && tris == 1) {
    puts("Full House!");
    *current += 6;
  } else if (pairs == 1 && tris == 0) {
    puts("Pair");
    *current += 1;
  } else if (pairs == 0 && tris == 1) {
    puts("Three of a kind!");
    *current += 3;
  }

  return;
}

void colour(const unsigned int deck[][FACES], int *const current,
            const int hand) {

  for (size_t i = 0; i < SUITS; i++) {

    int c = 0;
    for (size_t j = 0; j < FACES; j++) {
      if (deck[i][j] == -hand) {
        c++;
      }
    }

    if (c == 5) {
      puts("Color!");
      *current += 5;
    }
  }

  return;
}

void straight(const int *const dealt, int *const current) {

  for (size_t i = 0; i < FACES; i++) {
    if (*(dealt + i) != 0) {
      for (size_t k = i; *(dealt + k) != 0; k++) {
        if (k == i + 4) {
          puts("Straight!");
          *current += 4;
        }
      }
    }
  }
  return;
}

void better(const int *const hands) {
  if (*hands > *(hands + 1)) {
    puts("First hand was better!");
  } else if (*hands == *(hands + 1)) {
    puts("Hands were equal");
  } else {
    puts("Second hand was better!");
  }
  return;
}

void print_deck(const unsigned int deck[][FACES]) {

  for (size_t i = 0; i < SUITS; i++) {
    for (size_t j = 0; j < FACES; j++) {
      printf("%u\t", deck[i][j]);
    }
    puts("");
  }
  return;
}

void print_dealt(const int *const dealt) {
  for (size_t i = 0; i < FACES; i++) {
    printf("%2d", *(dealt + i));
  }
  puts("");
  return;
}

