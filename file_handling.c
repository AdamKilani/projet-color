// file_handling.c

#include <stdio.h>
#include <string.h>
#include "file_handling.h"

int load_sequence_from_file(char filename[], char sequence[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        return 0;
    }

    // Read sequence from file
    if (fscanf(file, "%s", sequence) != 1) {
        printf("Error: Failed to read sequence from file %s.\n", filename);
        fclose(file);
        return 0;
    }

    fclose(file);
    return 1;
}
