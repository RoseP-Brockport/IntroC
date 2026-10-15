#ifndef COLORS_H
#define COLORS_H

#define MAX_COLORS (10)

/*
Fill in the rest of this Union. You need an unsigned int to hold the hex representation and 
a unsigned char array of 4 elements to store the RGBA representation. 
Index 0 = Red
Index 1 = Green
Index 2 = Blue
Index 3 = Alpha
*/
typedef union {
unsigned hex;
unsigned char RGBA[4];

    

} color;

extern void print_color(color c);
extern color set_red(color c, unsigned char red);
extern color set_green(color c, unsigned char green);
extern color set_blue(color c, unsigned char blue);
extern color set_alpha(color c, unsigned char alpha);
extern void read_colors(color colors[]);

#endif
