#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <stdbool.h>
#include "mastermind.h"

/**
 * @brief Loads the secret code from a file.
 * 
 * This function reads the secret code from a file and stores it in the given `secretCode` array.
 * The function returns 0 if the secret code is loaded successfully, or a negative error code otherwise.
 *
 * @param filename The name of the file containing the secret code.
 * @param secretCode The array to store the secret code in.
 * @return int 0 if the secret code is loaded successfully, or a negative error code otherwise.
 */
int loadSecretCodeFromFile(const char *filename, Color secretCode[]);

/**
 * @brief Checks if a sequence of colors is valid.
 * 
 * This function checks if a sequence of colors is valid, i.e., if all colors in the sequence are valid.
 *
 * @param sequence The array of colors to check.
 * @param length The number of colors in the sequence.
 * @return bool True if the sequence is valid, false otherwise.
 */
bool isValidColorSequence(Color sequence[], int length);

#endif // FILE_HANDLING_H



#include <stdio.h>
#include <stdlib.h>
#include "file_handling.h"
#include "mastermind.h"

/**
 * @brief Loads the secret code from a file.
 * 
 * This function reads the secret code from a file and stores it in the given `secretCode` array.
 * The function returns 0 if the secret code is loaded successfully, or a negative error code otherwise.
 *
 * @param filename The name of the file containing the secret code.
 * @param secretCode The array to store the secret code in.
 * @return int 0 if the secret code is loaded successfully, or a negative error code otherwise.
 * @details The function first opens the file with the given name in read mode.
 * If the file cannot be opened, the function returns -1.
 * Then, the function reads colors from the file
