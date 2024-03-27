#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include "mastermind.h"

int loadSecretCodeFromFile(const char *filename, Color secretCode[]);
int isValidColorSequence(Color sequence[]);

#endif // FILE_HANDLING_H
