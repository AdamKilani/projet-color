#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mastermind.h"
#include "file_handling.h"

#define COLOR_STR_LENGTH 20

void print_color_options(void);
Color string_to_color(const char *color_str);
void print_colors(Color *colors, int length);

int main() {
    Color secret_code[CODE_LENGTH];
    Color guess[CODE_LENGTH];

    printf("Welcome to Mastermind!\n");
    print_color_options();

    // Ask the user if they want to load the secret code from a file or generate it randomly
    int choice;
    printf("\nChoose an option:\n");
    printf("1. Load secret code from file\n");
    printf("2. Generate random secret code\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume the newline character

    switch (choice) {
        case 1: {
            char filename[100];
            printf("Enter the file name: ");
            scanf("%s", filename);
            getchar(); // consume the newline character

            if (!loadSecretCodeFromFile(filename, secret_code)) {
                printf("Error: Unable to load the secret code from the file.\n");
                return 1;
            }
            printf("Secret code loaded from file.\n");
            break;
        }
        case 2:
            generateSecretCode(secret_code);
            printf("Random secret code generated.\n");
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return 1;
    }

    printInstructions();

    for (int num_guesses = 0; num_guesses < MAX_GUESSES; num_guesses++) {
        printf("\nEnter your guess (e.g., Red Green Blue Purple): ");
        for (int i = 0; i < CODE_LENGTH; i++) {
            char color_str[COLOR_STR_LENGTH];
            scanf("%s", color_str);
            guess[i] = string_to_color(color_str);
        }
        getchar(); // consume the newline character

        evaluateGuess(secret_code, guess);

        if (countCorrect(secret_code, guess) == CODE_LENGTH) {
            printf("\nCongratulations! You've guessed the code!\n");
            break;
        }
    }

    printf("\nThe secret code was: ");
    print_colors(secret_code, CODE_LENGTH);
    printf("\n");

    return 0;
}

void print_color_options(void
