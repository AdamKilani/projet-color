// color_library.c

#include <stdio.h>
#include "color_library.h"

void print_in_color(char text[], char color[]) {
    printf("%s%s%s", color, text, RESET);
}
