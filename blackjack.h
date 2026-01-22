#ifndef BLACKJACK_H
#define BLACKJACK_H

typedef struct {
    int number;       // Card number (1-10)
    char suit[10];    // Card suit ("Hearts", "Diamonds", "Clubs", "Spades")
} Card;

// Function prototypes
Card dealCard(void);
int calculateHand(Card hand[], int numCards);
void printHand(Card hand[], int numCards, int hideFirstCard);

#endif
