#include <stdlib.h>
#include <stdio.h>

#include "colors.h"

/*
Prints the provided color in the following format:

0xalpha,blue,green,red
Hex: 0x11223344
Red:   val
Green: val
Blue:  val
Alpha: val

Reminder: The hex value and the rgba may not be in the same order.
Red likely corresponds to 44, Alpha likely corresponds to 11
In some systems you may see
Red corresponding to 11 and Alpha corresponding to 44

IF YOUR HEX OUTPUT IS REVERSED FROM MINE, IT IS FINE

@param c The color union to print.
*/
void print_color(color c) {

}

/*
Sets the Red value in the union to the provided red value
@param c The color union to edit
@param red the new value to use for Red in the union

@return the modified union.
*/
color set_red(color c, unsigned char red) {
    return c;
}

/*
Sets the Green value in the union to the provided green value
@param c The color union to edit
@param green the new value to use for Green in the union

@return the modified union.
*/
color set_green(color c, unsigned char green) {
    return c;
}   

/*
Sets the Blue value in the union to the provided blue value
@param c The color union to edit
@param blue the new value to use for Blue in the union

@return the modified union.
*/
color set_blue(color c, unsigned char blue) {
    return c;
}

/*
Sets the Alpha value in the union to the provided Alpha value
@param c The color union to edit
@param alpha the new value to use for Alpha in the union

@return the modified union.
*/
color set_alpha(color c, unsigned char alpha) {
    return c;
}

/*
Reads in the colors and populates the provided colors array with the read in data.
Must use the getchar() function.
This function reads in all colors with a single call and populates the entire array

Hint: strtol(your_string_here, NULL, 16) can be used to get the hex value for the Union

@param colors The array of collors to fill with values read in with getchar()
*/
void read_colors(color colors[]) {
    char tempstring[11];
    // 
    
    
}
