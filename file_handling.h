#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdbool.h>
#include "mastermind.h"

int loadSecretCodeFromFile(const char *filename, Color secretCode[]);
bool isValidColorSequence(Color sequence[], int length);

#endif // FILE_HANDLING_H



#include <stdio.h>
#include <stdlib.h>
#include "file_handling.h"
#include "mastermind.h"

int loadSecretCodeFromFile(const char *filename, Color secretCode[])
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1; // error opening file
    }

    int count = 0;
    while (fscanf(file, "%c", &secretCode[count]) == 1) {
        if (!isValidColor(secretCode[count])) {
            fclose(file);
            return -2; // error: invalid color in file
        }
        count++;
        if (count >= MAX_SECRET_CODE_LENGTH) {
            break;
        }
    }
    fclose(file);

    if (count < MAX_SECRET_CODE_LENGTH) {
        return -3; // error: file does not contain enough colors
    }

    return 0; // success
}

bool isValidColorSequence(Color sequence[], int length)
{
    for (int i = 0; i < length; i++) {
        if (!isValidColor(sequence[i])) {
            return false;
        }
    }
    return true;
}
