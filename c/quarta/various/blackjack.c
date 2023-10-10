// Blackjack program
//
// Created by: Kaitlyn Lavan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator
    srand(time(NULL));
    // Declare and initialize variables
    int playerCard1 = 0, playerCard2 = 0, playerTotal = 0;
    int dealerCard1 = 0, dealerCard2 = 0, dealerTotal = 0;
    char hitOrStay = 'h';
    // Print welcome message
    printf("Welcome to Blackjack!\n\n");
    // Deal cards to player and dealer
    printf("Your cards:\n");
    playerCard1 = rand() % 10 + 1;
    playerCard2 = rand() % 10 + 1;
    playerTotal = playerCard1 + playerCard2;
    printf("   Card 1: %d\n", playerCard1);
    printf("   Card 2: %d\n", playerCard2);
    printf("   Total: %d\n\n", playerTotal);
    printf("Dealer's cards:\n");
    dealerCard1 = rand() % 10 + 1;
    dealerCard2 = rand() % 10 + 1;
    dealerTotal = dealerCard1 + dealerCard2;
    printf("   Card 1: %d\n", dealerCard1);
    printf("   Card 2: %d\n", dealerCard2);
    printf("   Total: %d\n\n", dealerTotal);
    // Ask player if they want to hit or stay
    printf("Hit or stay? (h/s): ");
    scanf(" %c", &hitOrStay);
    // Keep asking player if they want to hit or stay until they stay or bust
    while (hitOrStay == 'h' && playerTotal < 21) {
        playerCard1 = rand() % 10 + 1;
        printf("Your card: %d\n", playerCard1);
        playerTotal += playerCard1;
        printf("Your total: %d\n\n", playerTotal);
        if (playerTotal < 21) {
            printf("Hit or stay? (h/s): ");
            scanf(" %c", &hitOrStay);
        }
    }
    // Dealer hits until they get 17 or higher
    while (dealerTotal < 17) {
        dealerCard1 = rand() % 10 + 1;
        printf("Dealer's card: %d\n", dealerCard1);
        dealerTotal += dealerCard1;
        printf("Dealer's total: %d\n\n", dealerTotal);
    }
    // Print out who won
    if (playerTotal > 21) {
        printf("You busted! Dealer wins!\n");
    } else if (dealerTotal > 21) {
        printf("Dealer busted! You win!\n");
    } else if (playerTotal > dealerTotal) {
        printf("You win!\n");
    } else if (dealerTotal > playerTotal) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}
