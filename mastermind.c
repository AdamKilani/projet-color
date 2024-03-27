#include "mastermind.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSecretCode(Color secretCode[]) {
    srand(time(NULL));
    for (int i = 0; i < CODE_LENGTH; i++) {
        secretCode[i] = (Color)(rand() % 6);
    }
}

void printInstructions() {
    printf("Welcome to Mastermind!\n");
    printf("You have to guess a sequence of 4 secret colors in 10 tries or less.\n");
    printf("The available colors are: Red, Cyan, Yellow, Green, Blue, Purple\n");
    printf("You will receive feedback after each guess:\n");
    printf(" - Number of correct colors in the correct position (black pin)\n");
    printf(" - Number of correct colors in the wrong position (white pin)\n");
}

void printColors(Color colors[]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        print(colors[i]);
        printf(" ");
    }
    printf("\n");
}

void evaluateGuess(Color secretCode[], Color guess[], int guessNum) {
    int correct = countCorrect(secretCode, guess);
    int misplaced = countMisplaced(secretCode, guess);

    printf("| %-7d| ", guessNum);
    printColors(guess);
    printf("| black: %d, white: %d |\n", correct, misplaced);
}

int countCorrect(Color secretCode[], Color guess[]) {
    int count = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == secretCode[i]) {
            count++;
        }
    }
    return count;
}

int countMisplaced(Color secretCode[], Color guess[]) {
    int count = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        for (int j = 0; j < CODE_LENGTH; j++) {
            if (i != j && guess[i] == secretCode[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}
