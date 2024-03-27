#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mastermind.h"
#include "file_handling.h"

#define COLOR_STR_LENGTH 20

// Function to print the available color options for the user
void print_color_options(void) {
    printf("\nAvailable colors:\n");
    printf("1. Red\n");
    printf("2. Green\n");
    printf("3. Blue\n");
    printf("4. Purple\n");
    printf("5. Yellow\n");
    printf("6. Orange\n");
    printf("7. White\n");
    printf("8. Black\n");
}

// Function to convert a color string to its corresponding Color enumeration value
Color string_to_color(const char *color_str) {
    if (strcmp(color_str, "Red") == 0) {
        return RED;
    } else if (strcmp(color_str, "Green") == 0) {
        return GREEN;
    } else if (strcmp(color_str, "Blue") == 0) {
        return BLUE;
    } else if (strcmp(color_str, "Purple") == 0) {
        return PURPLE;
    } else if (strcmp(color_str, "Yellow") == 0) {
        return YELLOW;
    } else if (strcmp(color_str, "Orange") == 0) {
        return ORANGE;
    } else if (strcmp(color_str, "White") == 0) {
        return WHITE;
    } else if (strcmp(color_str, "Black") == 0) {
        return BLACK;
    } else {
        return INVALID_COLOR;
    }
}

// Function to print an array of Color values as a string representation
void print_colors(Color *colors, int length) {
    for (int i = 0; i < length; i++) {
        switch (colors[i]) {
            case RED:
                printf("Red ");
                break;
            case GREEN:
                printf("Green ");
                break;
            case BLUE:
                printf("Blue ");
                break;
            case PURPLE:
                printf("Purple ");
                break;
            case YELLOW:
                printf("Yellow ");
                break;
            case ORANGE:
                printf("Orange ");
                break;
            case WHITE:
                printf("White ");
                break;
            case BLACK:
                printf("Black ");
                break;
            default:
                printf("Invalid Color ");
                break;
        }
    }
}

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
               
