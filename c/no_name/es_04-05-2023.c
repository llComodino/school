#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define POKER_HAND 5
#define HANDS 2

void shuffle (unsigned int [][FACES]);
void deal (unsigned int [][FACES], const char *const [], const char *const [], const int);
void pairs (const unsigned int [][FACES], int *const, const int);
void colour (const unsigned int [][FACES], int *const, const int);
void straight (const unsigned int [][FACES], int *const, const int);
void better (const int *const);
//debug
void print_deck (const unsigned int [][FACES]);

int main (void) {
    
    unsigned int deck[SUITS][FACES] = {0};
    int hands[HANDS] = {0};

    srand(time(NULL));

    shuffle(deck);

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {
        "Ace", "Two", "Three", "Four", 
        "Five", "Six", "Seven", "Eight", 
        "Nine", "Ten", "Jack", "Queen", "King"
    };

    for (int i = 0; i < HANDS; i++) {

        deal(deck, face, suit, i);

        // print_deck(deck);

        // Check for combinations
        pairs(deck, &hands[i], i);
        colour(deck, &hands[i], i);
        straight(deck, &hands[i], i);

        puts("");
    }

    better(hands);
    return 0;
}

void shuffle (unsigned int deck[][FACES]) {

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

void deal (unsigned int deck[][FACES], const char *const face[], const char *const suit[], const int hand) {

    for (size_t card = 1, dealt = 0; dealt < POKER_HAND; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t col = 0; col < FACES; col++) {
                if (deck[row][col] == card) {
                    deck[row][col] = -hand;
                    dealt++;
                    printf("%5s of %-8s\n", face[col], suit[row]);
                }
            }
        }
    }
    puts("");
    return;
}

void pairs (const unsigned int deck[][FACES], int *const current, const int hand) {

    for (size_t i; i < FACES; i++) {

        int c = 0;
        for (size_t j = 0; j < SUITS; j++) {
            if (deck[j][i] == -hand) {
                c++;
            }
        }

        if (c == 2) {
            puts("Pair");
            *current += 1;
        }
        else if (c == 3) {
            puts("Tris");
            *current += 2;
        }
        else if (c == 4) {
            puts("Four of a kind!");
            *current += 3;
        }
    }
    return;
}

void colour (const unsigned int deck[][FACES], int *const current, const int hand) {

    for (size_t i = 0; i < SUITS; i++) {
        
        int c = 0;
        for (size_t j = 0; j < FACES; j++) {
            if (deck[i][j] == -hand) {
                c++;
            }
        }

        if (c == 5) {
            puts("Color!");
            *current += 4;
        }
    }

    return;
}

void straight (const unsigned int deck[][FACES], int *const current, const int hand) {

    for (size_t i = 0; i < SUITS; i++) {
        for (size_t j = 0; j < FACES - 4; j++) {
            if (deck[i][j] == -hand) {
                int c = 1;
                for (size_t k = j + 1; k < j + 5; k++) {
                    if (deck[i][k] == -hand) {
                        c++;
                    }
                }

                if (c == 5) {
                    puts("Straight!");
                    *current += 5;
                }
            }
        }
    }
    return;
}

void better (const int *const hands) {
    if (*hands > *(hands + 1)) {
        puts("First hand was better!");
    } else if (*hands == *(hands + 1)){
        puts("Hands were equal");
    } else {
        puts("Second hand was better!");
    }
    return;
}

void print_deck (const unsigned int deck[][FACES]) {

    for (size_t i = 0; i < SUITS; i++) {
        for (size_t j = 0; j < FACES; j++) {
            printf("%u\t", deck[i][j]);
        }
        puts("");
    }
    return;
}
