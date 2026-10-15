#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "unit_tests.h"
#include "practice1.h"

// This function is implemented incorrectly. You need to correct it.
// This function is supposed to check whether the integer pointed to
// by first is positive. If so, add its value to the integer pointed
// to by second, set the first integer to 0, and return 1.
// Otherwise, leave both integers unchanged and return 0.
// Be sure to eliminate all warnings for this code!
// You may need to run make clean before make to see warnings
int fix_bad_code( int *first, int *second ){
    if ( *first > 0 )
    {
        *second = *second + *first;
        *first = 0;
        return 1;
    }
    else if ( *first <= 0 ) // this could just be an else
    {
        return 0;
    }
    //adding return to remove warning as it can get through function without returning of current
    return 0;
}

// Returns the number of doubled up letters found in given string. 
// multiple pairs should be counted separately, for example
// "aaa" would return 2, as the first two letters, and the last two letters 
// are counted independently 
// You can assume that the provided string will contain 
// only lowercase letters and spaces. 
// Spaces cannot be counted as a part of pairs
// Example: "aabbccc" returns 4
int count_pairs(char sentence[]) {
    int doubles = 0;
    for(int i = 0;; i++){
        if(sentence[i] == '\0'){
            break;
        }
        if(i != 0 && sentence[i] == sentence[i-1] && (int)sentence[i] != 32 ){
            doubles += 1;
        }
    }
    return doubles;

}

// This function takes a string and converts all capital letters to
// lower case and all lowercase characters to upper case 
// After changing all letters, the number of changes made is returned
// Example: "abcdEFGH 10" is converted to "ABCDefgh 10" and 8 is returned.
// HINT: upper case letters are decimal 65 (A) through decimal 90 (Z).
//       lower case letters are decimal 97 (a) through decimal 122 (z)
// You may not use functions like islpha, strlen, toupper, etc. 
int swap_case(char sentence[]) {
    int lettertemp;
    int changes = 0;
    for(int i = 0;; i++){
        if(sentence[i] == '\0'){
            break;
        }
        lettertemp = (int)sentence[i];
        // A -> a = +32
        if(sentence[i] >= 65 && sentence[i] <= 90 ){
            lettertemp += 32;
            changes++;
        }
        if(sentence[i] >= 97 && sentence[i] <= 122){
            lettertemp -= 32;
            changes++;
        }
        sentence[i] = (char)lettertemp;
        
    }
    return changes;

}

// This function locates the last occurence of a target character
// in a string and returns the index of that occurence
// If the target character is not found, return -1. 
// You may not use functions like islpha, strlen, toupper, etc. 
int last_occurence(char sentence[], char target) {
    int index = -1;
    for(int i = 0;; i++){
        if(sentence[i] == '\0'){
            break;
        }
        if(sentence[i] == target){
            index = i;
        }

    }
    return index;

}

// This function finds the next capital letter after the start_index
// 1. If sentence[start_index] is a capital letter, it returns the start_index
// 2. If sentence[start_index] is not a capital letter, it moves to 
//    the next position until it either finds the end of the string 
//    or finds a capital letter.
//    If no capital letter is found, it returns -1 
// 3. If sentence[start_index] is the end of the string, return -1
// You may assume that the string contains only letters and spaces
// Hint: Capital Letter ASCII codes are 65 (A) through 90 (Z)
// You may not use functions like islpha, strlen, toupper, etc.
int find_next_capital(char sentence[], int start_index) {
    if(sentence[start_index] == '\0'){
        return -1;
    }
    for(int i = start_index;; i++){

        if(sentence[i] == '\0'){
            return -1;
        }
        if(sentence[i] >= 65 && sentence[i] <= 90){
            return i;
        }
    }
    return -1;

}


// This function takes in an input integer array and determines the following:
// 1. The number of odd numbers
// 2. the number of even numbers
// 3. the number of numbers that are multiples of 7
// These values are placed into the 'numerics' structure and this structure
// is returned.
// The maxmimum length of an array is given as a constant 
// in unit_tests.h, MAX_ARRAY
// All arrays will be the maximum length
// A copy of the structure from practice1.h for your reference:
// typedef struct {
//     int num_evens;
//     int num_odds;
//     int num_sevens;
// } numerics;
numerics classify_digits(int data[]) {
    numerics values = {0,0,0};
    for(int i = 0; i < MAX_ARRAY; i++){
        if(data[i] % 2 != 0){values.num_odds++;}
        if(data[i] % 2 == 0){values.num_evens++;}
        if(data[i] % 7 == 0){values.num_sevens++;}
    }
    return values;

}


int main() {

    return test();

}
