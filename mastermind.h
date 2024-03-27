#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "color_library.h"

#define CODE_LENGTH 4
#define MAX_GUESSES 10

typedef enum {
    Red, Cyan, Yellow, Green, Blue, Purple
} Color;

void generateSecretCode(Color secretCode[]);
void printInstructions();
void printColors(Color colors[]);
void evaluateGuess(Color secretCode[], Color guess[], int guessNum);
int countCorrect(Color secretCode[], Color guess[]);
int countMisplaced(Color secretCode[], Color guess[]);

#endif // MASTERMIND_H

