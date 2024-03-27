#ifndef COLOR_LIBRARY_H // If the COLOR_LIBRARY_H symbol is not defined
#define COLOR_LIBRARY_H // Define the COLOR_LIBRARY_H symbol

// Define a custom data type 'Color' as an enumeration of color constants
typedef enum {
    Red,    // Constant for the color red
    Cyan,   // Constant for the color cyan
    Yellow, // Constant for the color yellow
    Green,  // Constant for the color green
    Blue,   // Constant for the color blue
    Purple  // Constant for the color purple
} Color;

// Declare a function 'print' that takes a Color as an argument
void print(Color color);

#endif // COLOR_LIBRARY_H

