#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <stdbool.h>
#include "color_library.h"

#define CODE_LENGTH 4
#define MAX_GUESSES 10

typedef char Color[10];

void generateSecretCode(Color secretCode[]);
void printInstructions();
void printColors(Color colors[]);
void evaluateGuess(Color secretCode[], Color guess[], int guessNum);
int countCorrect(Color secretCode[], Color guess[]);
int countMisplaced(Color secretCode[], Color guess[]);
bool isGuessMade(Color guesses[], Color guess);
bool isGameOver(int guessNum);
void printGuessResult(int correct, int misplaced);

#endif // MASTERMIND_H

