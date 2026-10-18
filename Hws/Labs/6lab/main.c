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
    char building = '\0';
    int sensor = -1;
    double temp = -999.0;

    read_in(&building, &sensor, &temp);
    printf("Building %c Sensor %d Reports temperature of %.2f\n", building, sensor, temp);
    if(building == '\0' || sensor == -1 || temp == -999.0){
        return 1;
    }
    return 0;

}
