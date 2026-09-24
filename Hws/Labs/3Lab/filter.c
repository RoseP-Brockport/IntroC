#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"

/*
This function prints out a provided integer array. Elements are printed on a
single line with a comma seperating elements. Instead of the final element
being followed by a comma, it is followed by a new line.

@param to_print an array of integers to be printed
*/
void print_array(int to_print[]) {

for(int x = 0; x < 25; x++){
    // , after number if not last element, newline if last element
    char end = ',';
    if(x == 24){
        end = '\n';
    }

    printf("%d",to_print[x]);
    printf("%c",end);
}


    return;

}

/*
This function, when provided with two arrays, fills the second array with 
all the even numbers (not indexes) found in the original list. All 
remaining indexes at the end of the array that are not filled by an even 
number are filled with zeros.

Zero is considered as an even number when found in the original list.

@param origin_array the array to filter resulting matches from
@param to_array the array to fill with even numbers and zeros.
*/
void filter_evens(int origin_array[], int to_array[]) {

int to_array_place = 0;
for(int x = 0; x < 25; x++){
// if even (%2 == 0) put it in to_array, then increment to_array_place, to fill sequentially
if(origin_array[x]%2 == 0){
    to_array[to_array_place] = origin_array[x];
    to_array_place ++;
}

}

for(int x = 0; x < 25; x++){

    char end = ',';
    if(x == 24){
        end = '\n';
    }

    printf("%d",to_array[x]);
    printf("%c",end);
}


    return;

}

/*
This function, when provided with two arrays, fills the second array with
all the numbers found at odd indexes (not values). Unfilled indexes at the end 
of the array are filled with zeros.

@param origin_array the array to filter with resulting matches from
@param to_array the array to fill with numbers found at odd indexes and zeros.
*/
void filter_odd_indexes(int original_array[], int to_array[]) {


//same as filter even, but for (%2 == 1) instead
int to_array_place = 0;
for(int x = 0; x < 25; x++){

if(original_array[x]%2 == 1){
    to_array[to_array_place] = original_array[x];
    to_array_place ++;
}

}

for(int x = 0; x < 25; x++){

    char end = ',';
    if(x == 24){
        end = '\n';
    }

    printf("%d",to_array[x]);
    printf("%c",end);
}


    return;

}
