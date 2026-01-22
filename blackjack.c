#include "blackjack.h"
#include <stdio.h>
#include <stdlib.h>

// Deal a random card (1 to 10) with a random suit
Card dealCard(void) {
    Card newCard;
    newCard.number = rand() % 10 + 1;

    char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int randomIndex = rand() % 4;

    sprintf(newCard.suit, "%s", suits[randomIndex]);
    return newCard;
}

// Calculate the total value of a hand (Ace counts as 11 unless bust, then 1)
int calculateHand(Card hand[], int numCards) {
    int sum = 0;
    int numAces = 0;

    for (int i = 0; i < numCards; i++) {
        if (hand[i].number == 1) {
            numAces++;
            sum += 11;
        } else if (hand[i].number > 10) {
            sum += 10;
        } else {
            sum += hand[i].number;
        }
    }

    while (sum > 21 && numAces > 0) {
        sum -= 10;
        numAces--;
    }

    return sum;
}

// Print a hand of cards; optionally hide the first card (dealer)
void printHand(Card hand[], int numCards, int hideFirstCard) {
    for (int i = 0; i < numCards; i++) {
        if (i == 0 && hideFirstCard) {
            printf("[Hidden Card] ");
        } else {
            printf("[%d %s] ", hand[i].number, hand[i].suit);
        }
    }
    printf("\n");
}
