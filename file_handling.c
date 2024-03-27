#include "file_handling.h"
#include <stdio.h>
#include <string.h>

// Function to print an error message when there is an issue opening the file
static void print_error(const char *filename) {
    printf("Error: Could not open file %s\n", filename);
}

// Function to load the secret code from a file into the 'secret_code' array
// 'filename' is the name of the file to be loaded
// 'secret_code' is the array to store the loaded secret code
int load_secret_code_from_file(const char *filename, Color secret_code[]) {
    FILE *file = fopen(filename, "r"); // Open the file in read mode
    if (!file) { // If the file cannot be opened
        print_error(filename); // Print an error message
        return 0; // Return 0 to indicate failure
    }

    Color color;
    int index = 0;
    while (fscanf(file, "%d", &color) == 1) { // Read the color values from the file
        if (index >= CODE_LENGTH) { // If the array index exceeds the maximum allowed index
            print_error(filename); // Print an error message
            fclose(file); // Close the file
            return 0; // Return 0 to indicate failure
        }
        secret_code[index++] = color; // Store the color value in the array
    }

    fclose(file); // Close the file

    if (index != CODE_LENGTH) { // If the number of color values read is not equal to the expected number
        print_error(filename); // Print an error message
        return 0; // Return 0 to indicate failure
    }

    if (!is_valid_color_sequence(secret_code)) { // Check if the loaded sequence is valid
        printf("Error: Invalid color sequence in file %s (invalid colors)\n", filename);
        return 0; // Return 0 to indicate failure
    }

    return 1; // Return 1 to indicate success
}

// Function to check
