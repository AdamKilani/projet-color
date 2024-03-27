#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COLORS 6
#define CODE_LENGTH 4

typedef enum {
    RED,
    CYAN,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE
} Color;

void generateSecretCode(Color secretCode[]) {
    srand(time(NULL));
    for (int i = 0; i < CODE_LENGTH; i++) {
        secretCode[i] = (Color)(rand() % NUM_COLORS);
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

void printColor(Color color) {
    switch (color) {
        case RED:
            printf("Red");
            break;
        case CYAN:
            printf("Cyan");
            break;
        case YELLOW:
            printf("Yellow");
            break;
        case GREEN:
            printf("Green");
            break;
        case BLUE:
            printf("Blue");
            break;
        case PURPLE:
            printf("Purple");
            break;
    }
}

void printColors(Color colors[]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        printColor(colors[i]);
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
   
