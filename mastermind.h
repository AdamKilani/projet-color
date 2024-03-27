#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <stdbool.h>
#include "color_library.h"

/* Define the length of the secret code */
#define CODE_LENGTH 4

/* Define the maximum number of guesses allowed */
#define MAX_GUESSES 10

/* Define the type Color as an array of 10 characters */
typedef char Color[10];

/* Function to generate a secret code */
void generateSecretCode(Color secretCode[]);
/* This function generates a secret code of CODE_LENGTH colors.
   The secretCode array should be passed as an argument and will be
   populated with the generated secret code. */

/* Function to print the game instructions */
void printInstructions();
/* This function prints the instructions for the game to the console. */

/* Function to print the available colors */
void printColors(Color colors[]);
/* This function prints the list of available colors to the console. */

/* Function to evaluate a guess */
void evaluateGuess(Color secretCode[], Color guess[], int guessNum);
/* This function evaluates a guess made by the user. The secretCode,
   guess, and guessNum (the number of the current guess) are passed
   as arguments. The function should calculate the number of correct
   and misplaced colors in the guess and print the result to the console. */

/* Function to count the number of correct colors in a guess */
int countCorrect(Color secretCode[], Color guess[]);
/* This function counts the number of colors in the guess that are
   in the correct position in the secret code. The secretCode and
   guess arrays are passed as arguments. The function returns the
   number of correct colors. */

/* Function to count the number of misplaced colors in a guess */
int countMisplaced(Color secretCode[], Color guess[]);
/* This function counts the number of colors in the guess that are
   in the secret code, but in the wrong position. The secretCode and
   guess arrays are passed as arguments. The function returns the
   number of misplaced colors. */


