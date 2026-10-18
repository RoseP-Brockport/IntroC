#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pointer_in.h"

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




void read_in(char* building, int* sensor, double* temp) {
    *building = getchar();
    char arr[MAX_LINE] = {'\0'};
    // - 2 for -1  0-index, -1 for already done first char
    for(int i = 0; i < MAX_LINE-2; i++){

        arr[i] = getchar();
        if(arr[i] == ','){
            arr[i] = '\0';
            *sensor = atoi(arr);
            break;
        }
    }
    // its a good way to do this i promise
    memset(arr, '\0', sizeof(MAX_LINE));
    //-4 for worst case, sensor 1 digit, building 1 digit, comma 1 thingie, 1 for 0-index
    for(int i = 0; MAX_LINE-4; i++){
        arr[i] = getchar();
        if(arr[i] == '.'){
            arr[i+1] = getchar();
            arr[i+2] = getchar();
            *temp = atof(arr);
            break;
        }
    }
    return;

}
