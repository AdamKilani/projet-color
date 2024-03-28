// mastermind.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mastermind.h"
#include "file_handling.h"
#include "color_library.h"

// Define colors
#define RED   "\x1B[31m"
#define CYAN  "\x1B[36m"
#define YELLOW "\x1B[33m"
#define GREEN "\x1B[32m"
#define BLUE  "\x1B[34m"
#define PURPLE "\x1B[35m"
#define RESET "\x1B[0m"

void print_game_board(char guesses[][MAX_GUESS_LENGTH], int results[][2], int num_guesses) {
    printf("| guess # | guess | result             |\n");
    printf("| ------- | ----- | ------------------ |\n");
    for (int i = 0; i < num_guesses; i++) {
        printf("| %-7d | %s | black: %d, white: %d |\n", i+1, guesses[i], results[i][0], results[i][1]);
    }
}

void generate_secret_sequence(char secret_sequence[]) {
    // Generate a random secret sequence
    char colors[] = {'R', 'C', 'Y', 'G', 'B', 'P'};
    srand(time(NULL));
    for (int i = 0; i < SECRET_SEQUENCE_LENGTH; i++) {
        secret_sequence[i] = colors[rand() % NUM_COLORS];
    }
}

void evaluate_guess(char secret_sequence[], char guess[], int* black_pins, int* white_pins) {
    // Initialize arrays to keep track of matched colors
    int secret_count[NUM_COLORS] = {0};
    int guess_count[NUM_COLORS] = {0};

    // Count black pins (correct color and position)
    *black_pins = 0;
    for (int i = 0; i < SECRET_SEQUENCE_LENGTH; i++) {
        if (secret_sequence[i] == guess[i]) {
            (*black_pins)++;
        } else {
            // Count each color occurrence in secret and guess
            secret_count[secret_sequence[i] - 'A']++;
            guess_count[guess[i] - 'A']++;
        }
    }

    // Count white pins (correct color but wrong position)
    *white_pins = 0;
    for (int i = 0; i < NUM_COLORS; i++) {
        *white_pins += (secret_count[i] < guess_count[i]) ? secret_count[i] : guess_count[i];
    }
    *white_pins -= *black_pins;
}

void play_mastermind() {
    char secret_sequence[SECRET_SEQUENCE_LENGTH + 1]; // +1 for null terminator
    char guesses[MAX_GUESSES][MAX_GUESS_LENGTH];
    int results[MAX_GUESSES][2]; // 2D array to store black and white pins for each guess

    int num_guesses = 0;
    int black_pins, white_pins;

    // Initialize the secret sequence
    generate_secret_sequence(secret_sequence);

    // Main game loop
    while (num_guesses < MAX_GUESSES) {
        printf("Enter your guess (e.g., RYBG): ");
        scanf("%s", guesses[num_guesses]);

        // Evaluate the guess
        evaluate_guess(secret_sequence, guesses[num_guesses], &black_pins, &white_pins);
        results[num_guesses][0] = black_pins;
        results[num_guesses][1] = white_pins;

        // Display the game board
        printf("\n");
        print_game_board(guesses, results, num_guesses + 1);
        printf("\n");

        // Check for victory
        if (black_pins == SECRET_SEQUENCE_LENGTH) {
            printf("Congratulations! You've cracked the code!\n");
            return;
        }

        num_guesses++;
    }

    // If loop exits, player has run out of guesses
    printf("Sorry, you've run out of guesses. The secret sequence was: %s\n", secret_sequence);
}
