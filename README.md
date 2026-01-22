# Console Blackjack Game (C)

This project is a command-line Blackjack game written in C. The player starts with a fixed amount of money, places bets, and plays against a dealer following standard Blackjack rules. The player can choose to hit or stand, the dealer hits until reaching 17, and hand values are calculated with Ace handling (11 or 1 to prevent busting). The game continues until the player quits or runs out of money.

## Features
- Betting system with money tracking
- Random card dealing with suits (Hearts, Diamonds, Clubs, Spades)
- Player actions: `hit` or `stand`
- Dealer logic: hits until hand value is at least 17
- Ace logic: counts as 11 unless it causes a bust (then becomes 1)
- Dealer’s first card is hidden during the player’s turn

## Project Structure
- `main.c` – Game loop, betting, player/dealer turns
- `blackjack.h` – Card struct + function prototypes
- `blackjack.c` – Card dealing, hand calculation, and printing helpers

## How to Compile and Run

### Compile
```bash
gcc main.c blackjack.c -o blackjack
