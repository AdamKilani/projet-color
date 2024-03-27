#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"
#include "file_handling.h"

int main() {
    Color secretCode[CODE_LENGTH];
    Color guess[CODE_LENGTH];

    printf("Welcome to Mastermind!\n");

    // Ask the user if they want to load the secret code from a file or generate it randomly
    int choice;
    printf("Choose an option:\n");
    printf("1. Load secret code from file\n");
    printf("2. Generate random secret code\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume the newline character

    switch (choice) {
        case 1:
            if (!loadSecretCodeFromFile("secret-sequence.txt", secretCode)) {
                printf("Exiting...\n");
                return 1;
            }
            printf("Secret code loaded from file.\n");
            break;
        case 2:
            generateSecretCode(secretCode);
            printf("Random secret code generated.\n");
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    printInstructions();

    for (int numGuesses = 0; numGuesses < MAX_GUESSES; numGuesses++) {
        printf("Enter your guess (e.g., Red Green Blue Purple): ");
        for (int i = 0; i < CODE_LENGTH; i++) {
            char colorStr[20];
            scanf("%s", colorStr);
            guess[i] = stringToColor(colorStr);
        }
        getchar(); // consume the newline character

        evaluateGuess(secretCode, guess);

        if (countCorrect(secretCode, guess) == CODE_LENGTH) {
            printf("Congratulations! You've guessed the code!\n");
            break;
        }
    }

    printf("The secret code was: ");
    printColors(secretCode);
    printf("\n");

    return 0;
}
