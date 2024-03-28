// mastermind.h

#ifndef MASTERMIND_H
#define MASTERMIND_H

#define SECRET_SEQUENCE_LENGTH 4
#define MAX_GUESSES 10
#define MAX_GUESS_LENGTH (SECRET_SEQUENCE_LENGTH + 1) // +1 for null terminator
#define NUM_COLORS 6

void play_mastermind();

#endif
