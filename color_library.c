#include "color_library.h"
#include <stdio.h>

void print(Color color) {
    switch (color) {
        case Red:
            printf("\033[0;31mRed\033[0m");
            break;
        case Cyan:
            printf("\033[0;36mCyan\033[0m");
            break;
        case Yellow:
            printf("\033[0;33mYellow\033[0
