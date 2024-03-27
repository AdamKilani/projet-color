#include "file_handling.h"
#include <stdio.h>
#include <string.h>

int loadSecretCodeFromFile(const char *filename, Color secretCode[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    Color color;
    int index = 0;
    while (fscanf(file, "%d", &color) == 1) {
        if (index >= CODE_LENGTH) {
            printf("Error: Invalid color sequence in file %s (too long)\n", filename);
            fclose(file);
            return 0;
        }
        secretCode[index++] = color;
    }

    fclose(file);

    if (index != CODE_LENGTH) {
        printf("Error: Invalid color sequence in file %s (too short)\n", filename);
        return 0;
    }

    if (!isValidColorSequence(secretCode)) {
        printf("Error: Invalid color sequence in file %s (invalid colors)\n", filename);
        return 0;
    }

    return 1;
}

int isValidColorSequence(Color sequence[]) {
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (sequence[i] < Red || sequence[i] > Purple) {
            return 0;
        }
    }
    return 1;
}
