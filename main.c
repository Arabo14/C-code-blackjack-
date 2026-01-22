#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "blackjack.h"

int main(void) {
    srand((unsigned int)time(NULL)); // Seed random number generator

    Card playerHand[10];
    Card dealerHand[10];
    int numPlayerCards = 0;
    int numDealerCards = 0;
    int playerMoney = 1000;
    int bet;

    printf("Welcome to Blackjack!\n\n");

    while (playerMoney > 0) {
        printf("You have $%d.\n", playerMoney);
        printf("Place your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            printf("Thanks for playing! You leave with $%d.\n", playerMoney);
            break;
        }
        if (bet > playerMoney) {
            printf("You don't have enough money. Please place a lower bet.\n");
            continue;
        }

        // Reset hands
        numPlayerCards = 0;
        numDealerCards = 0;

        // Deal initial cards
        playerHand[numPlayerCards++] = dealCard();
        playerHand[numPlayerCards++] = dealCard();
        dealerHand[numDealerCards++] = dealCard();
        dealerHand[numDealerCards++] = dealCard();

        printf("\n");

        // Player's turn
        printf("Your hand: ");
        printHand(playerHand, numPlayerCards, 0);

        printf("Dealer's hand: ");
        printHand(dealerHand, numDealerCards, 1);
        printf("\n");

        // Player actions
        char choice[10];
        while (1) {
            printf("Do you want to hit or stand? ");
            scanf("%s", choice);

            if (strcmp(choice, "hit") == 0) {
                playerHand[numPlayerCards++] = dealCard();
                printf("Your hand: ");
                printHand(playerHand, numPlayerCards, 0);

                if (calculateHand(playerHand, numPlayerCards) > 21) {
                    printf("Bust! You lose $%d.\n", bet);
                    playerMoney -= bet;
                    break;
                }
            } else if (strcmp(choice, "stand") == 0) {
                break;
            } else {
                printf("Invalid choice. Please try again.\n");
            }
        }

        if (calculateHand(playerHand, numPlayerCards) > 21) {
            printf("\n");
            continue;
        }

        // Dealer's turn
        printf("Dealer's turn:\n");
        printf("Dealer's hand: ");
        printHand(dealerHand, numDealerCards, 0);

        while (calculateHand(dealerHand, numDealerCards) < 17) {
            dealerHand[numDealerCards++] = dealCard();
            printf("Dealer hits: ");
            printHand(dealerHand, numDealerCards, 0);
        }

        // Determine winner
        int playerScore = calculateHand(playerHand, numPlayerCards);
        int dealerScore = calculateHand(dealerHand, numDealerCards);

        printf("\nYour score: %d\n", playerScore);
        printf("Dealer's score: %d\n", dealerScore);

        if (dealerScore > 21 || playerScore > dealerScore) {
            printf("You win $%d!\n", bet);
            playerMoney += bet;
        } else if (dealerScore > playerScore) {
            printf("Dealer wins. You lose $%d.\n", bet);
            playerMoney -= bet;
        } else {
            printf("It's a tie! Your bet is returned.\n");
        }

        printf("\n");
    }

    return 0;
}
