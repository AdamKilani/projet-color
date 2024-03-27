#include "file_handling.h"
#include <stdio.h>
#include <string.h>

static void print_error(const char *filename) {
    printf("Error: Could not open file %s\n", filename);
}

int load_secret_code_from_file(const char *filename, Color secret_code[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        print_error(filename);
        return 0;
    }

    Color color;
    int index = 0;
    while (fscanf(file, "%d", &color) == 1) {
        if (index >= CODE_LENGTH) {
            print_error(filename);
            fclose(file);
            return 0;
        }
        secret_code[index++] = color;
    }

    fclose(file);

    if (index != CODE_LENGTH) {
        print_error(filename);
        return 0;
    }

    if (!is_valid_color_sequence(secret_code)) {
        printf("Error: Invalid color sequence in file %s (invalid colors)\n", filename);
        return 0;
    }

    return 1;
}

int is_valid_color_sequence(Color sequence[]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (sequence[i] < Red || sequence[i] > Purple) {
            return 0;
        }
    }
    return 1;
}
