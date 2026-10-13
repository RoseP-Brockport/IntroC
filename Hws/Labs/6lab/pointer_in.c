#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "pointers_in.h"

/*
This function reads from standard in (using getchar().
Input comes in the form: BX,D 
Where:
    B is a single letter indicating a building
    X is an integer of variable length representing the thermostat ID
    D is a double of variable length representing the temperature
Only a single line of input will be provided in < file.txt syntax
You must use atoi to convert the integer and atof for the double

COMPLETE THIS DOCUMENTATION WITH YOUR PARAMETERS

*/
void read_in(/*Fill in paramaters*/) {


    // read in from input of for BD,T
    // read Char (always 1 letter)
    // read integers until hit ,
    //read numbers until hit .    - then read 2 more
    // format / cast to correct - send pointers back to llalaa
    

    int backsensor = 0;
    int intcrement = 0;
    char building = getchar();
    

    while(true){
        char staging = getchar();
        if (staging == ','){
            break;
        }
        else {
            strcat()
            backsensor += (atoi(staging)*(pow(10,intcrement)))
            intcrement ++;
        }
    }

    while(true){
        char staging = getchar();
        if(staging == "."){
            break;
        }
        else {
            
        }

    }


    return;

}
