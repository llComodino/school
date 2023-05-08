#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define POKER_HAND 5

void shuffle (unsigned int [][FACES]);
void deal (unsigned int [][FACES], const char *const [], const char *const []);
int pairs (const unsigned int [][FACES]);
bool colour (const unsigned int [][FACES]);
bool straight (const unsigned int [][FACES]);

//debug
void print_deck (const unsigned int [][FACES]);

int main (void) {
    
    unsigned int deck[SUITS][FACES] = {0};
    srand(time(NULL));

    shuffle(deck);

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {
        "Ace", "Two", "Three", "Four", 
        "Five", "Six", "Seven", "Eight", 
        "Nine", "Ten", "Jack", "Queen", "King"
    };

    deal(deck, face, suit);

    // print_deck(deck);

    int pair = pairs(deck);

    puts("");

    switch (pair) {
        
        case 1:
            puts("Pair");
            break;

        case 2:
            puts("Tris");
            break;

        case 3:
            puts("Four of a kind!");
            break;

        default:
            puts("");
    }

    if (colour(deck)) {
        puts("Colour!");
    }

    if (straight(deck)) {
        puts("Straight!");
    }

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

void deal (unsigned int deck[][FACES], const char *const face[], const char *const suit[]) {

    for (size_t card = 1; card <= POKER_HAND; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t col = 0; col < FACES; col++) {
                if (deck[row][col] == card) {
                    deck[row][col] = 0;
                    printf("%5s of %-8s\n", face[col], suit[row]);
                }
            }
        }
    }
    return;
}

int pairs (const unsigned int deck[][FACES]) {

    for (size_t i = 0; i < FACES; i++) {

        int c = 0;
        for (size_t j = 0; j < SUITS; j++) {
            if (deck[j][i] == 0) {
                c++;
            }
        }
        if (c == 2) {
            return 1;
        }
        else if (c == 3) {
            return 2;
        }
        else if (c == 4) {
            return 3;
        }
    }

    return 0;
}

bool colour (const unsigned int deck[][FACES]) {

    for (size_t i = 0; i < SUITS; i++) {
        
        int c = 0;
        for (size_t j = 0; j < FACES; j++) {
            if (deck[i][j] == 0) {
                c++;
            }
        }

        if (c == 5) {
            return true;
        }
    }

    return false;
}

bool straight (const unsigned int deck[][FACES]) {

    for (size_t i = 0; i < SUITS; i++) {
        for (size_t j = 0; j < FACES - 4; j++) {
            if (deck[i][j] == 0) {
                int c = 1;
                for (size_t k = j + 1; k < j + 5; k++) {
                    if (deck[i][k] == 0) {
                        c++;
                    }
                }

                if (c == 5) {
                    return true;
                }
            }
        }
    }

    return false;
}

void print_deck (const unsigned int deck[][FACES]) {

    for (size_t i = 0; i < SUITS; i++) {
        for (size_t j = 0; j < FACES; j++) {
            printf("%u\t", deck[i][j]);
        }
        puts("");
    }
}
