int countCorrect(Color secretCode[], Color guess[]) {
    int count = 0;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (secretCode[i] == guess[i]) {
            count++;
        }
    }
    return count;
}

int countMisplaced(Color secretCode[], Color guess[]) {
    // countMisplaced function calculates and returns the number of correct colors in the wrong position between the secretCode and guess arrays.
    int count = 0;
    for (int i = 0; i < NUM_COLORS; i++) {
        int correctPosition = 0;
        for (int j = 0; j < CODE_LENGTH; j++) {
            if (secretCode[j] == (Color)i && guess[j] != (Color)i) {
                correctPosition++;
            }
        }
        if (correctPosition == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    // Initialize arrays to store the secret code and the user's guess.
    Color secretCode[CODE_LENGTH];
    Color guess[CODE_LENGTH];

    // Print the game instructions.
    printInstructions();

    // Generate the secret code.
    generateSecretCode(secretCode);

    // Main game loop.
    for (int i = 1; i <= 10; i++) {
        printf("Enter your guess %d: ", i);
        for (int j = 0; j < CODE_LENGTH; j++) {
            scanf("%d", &guess[j]);
            guess[j] = (Color)guess[j];
        }

        // Evaluate the user's guess and display the feedback.
        evaluateGuess(secretCode, guess, i);

        // Check if the user has guessed the secret code correctly.
        if (compareCodes(secretCode, guess)) {
            printf("Congratulations! You've guessed the secret code!\n");
            break;
        }
    }

    return 0;
}



int compareCodes(Color secretCode[], Color guess[]) {
    int equal = 1;
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (secretCode[i] != guess[i]) {
            equal = 0;
            break;
        }
    }
    return equal;
}
