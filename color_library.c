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
            printf("\033[0;33mYellow\033[0m");
            break;
        case Green:
            printf("\033[0;32mGreen\033[0m");
            break;
        case Blue:
            printf("\033[0;34mBlue\033[0m");
            break;
        case Purple:
            printf("\033[0;35mPurple\033[0m");
            break;
    }
}
