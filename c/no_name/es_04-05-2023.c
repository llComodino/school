#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle (unsigned int **const);
void deal (unsigned int **const, const char *const [], const char *const []);

int main (void) {
    
    unsigned int deck[SUITS][FACES];
    srand(time(NULL));

    puts("Shuffling...");
    shuffle(deck);

    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {
        "Ace", "Two", "Three", "Four", 
        "Five", "Six", "Seven", "Eight", 
        "Nine", "Ten", "Jack", "Queen", "King"
    };

    deal(deck, face, suit);

    return 0;
}

void shuffle (unsigned int **const deck) {


    printf("%d", *(1 + (deck + 3)));

    for (size_t card = 1; card <= CARDS; card++) {
        size_t row, col;

        do {
            row = rand() % SUITS;
            col = rand() % FACES;
        } while (*(row + (deck + col)) != 0);

        **(row + (deck + col)) = card;
    }
    return;
}

void deal (unsigned int **const deck, const char *const face[], const char *const suit[]) {

    for (size_t card = 1; card <= CARDS; card++) {
        for (size_t row = 0; row < SUITS; row++) {
            for (size_t col = 0; col < FACES; col++) {
                if (**(row + (deck + col)) == card) {
                    printf("%5s of %-8s%c", face[col], suit[row], card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
    return;
}
