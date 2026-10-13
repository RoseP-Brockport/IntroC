#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pointer_in.h"
/*
This main function does the following sequence:
1. Delcares local variables for the char, int, and double
2. Calls read data with pointers so the local variables can be updated
3. Prints the values of the local vairables in the format below:
    "Building %c Sensor %d Reports temperature of %.2f\n"
4. Returns 0 for EXIT SUCCESS
*/
int main() {

    char building = NULL;
    int sensor = NULL;
    // if ur sensor reads -200, either the code broke, or you have bigger problems than this being hardcoded to initialize
    double temp = -200;


    // return 0 for success, assume 1 for fail then
    read_in();

    printf("Building %c Sensor %d Reports temperature of %.2f\n", building, sensor, temp);

    return 0;

}
