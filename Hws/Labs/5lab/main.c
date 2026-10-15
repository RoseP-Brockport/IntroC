#include <stdio.h>
#include <stdlib.h>

#include "colors.h"

int main() {

    color colors[MAX_COLORS]; // Creates the array of colors to use for processing
    read_colors(colors); // Fill the color array

    // This loop just picks R,G,B, or A to change for each color in the array
    for (int i = 0; i < MAX_COLORS; i++) {
        if( i % 4 == 0)
            colors[i] = set_red(colors[i], 255);
        else if (i % 4 == 1) 
            colors[i] = set_green(colors[i], 255);
        else if (i % 4 == 2)
            colors[i] = set_blue(colors[i], 255);
        else 
            colors[i] = set_alpha(colors[i], 255);

        print_color(colors[i]); // Print 1 color
        printf("\n"); // Print a new line between each color
    }

    return 0;
    
}
