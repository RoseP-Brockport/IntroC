#include <stdlib.h>
#include <stdio.h>

#include "unit_tests.h"
#include "midterm.h"
// You may not use any functions from <ctype.h> or <string.h>.
// All string traversal, character classification, and character
// manipulation must be implemented manually using loops,
// conditionals, and ASCII character comparisons.
// Do not use library functions to calculate string lengths,
// search for characters, or convert character case.
// You may use characters themselves or their decimal representations


// This function is implemented incorrectly. You need to correct it.
// This function is supposed to compare the two integers pointed to
// by first and second. If the first integer is larger than the second,
// decrease the first integer by 1, increase the second integer by 1,
// and return 1. Otherwise, leave both integers unchanged and return 0.
// Be sure to eliminate all warnings for this code!
// You may need to run make clean before make to see warnings
// You may rewrite this function entirely if desired.
int fix_bad_code( int *first, int *second )
{
    if ( *first > *second )
    {
        *first -= 1;
        *second += 1;
        return 1;
    }
    else{
        return 0;
    }
}

// Returns the character immediately before the first occurence of the 
// target character in the string
// 1. If the target is not in the string, return '?'
// 2. If the target is the first character, return '?'
// 3. Otherwise return the character before the target in the string
// See comment at top of file
// You may not use functions like islpha, strlen, toupper, etc.
// Example: "hello" with 'l' as the target returns 'e'.
char preceding_char(char str[], char target) {

    for(int i = 0;; i++){
        if(str[i] == '\0'){
            break;
        }
        if(i == 0){
            if(str[i] == target){
                return '?';
            }
            else{
                continue;
            }
        }
        if(str[i] == target){
            return str[i-1];
        }
    }


    return '?';

}

// This function takes a string and rotates all lowercase characters 
// to the next one alphabetically. Non-lowercase characters are ignored.
// z is rotated back to a.
// It returns the total number of changes made to the string.
// Examples:
// "BrOcKpOrT" returns 4 while changing the string to "BsOdKqOsT"
// "xyz" returns 3 while changing the string to "yza"
// Hint:  lower case letters are decimal 97 (a) through decimal 122 (z)
// See comment at top of file
// You may not use functions like islpha, strlen, toupper, etc.

//26 chars
int lower_rotate(char str[]) {
    int change = 0;
    for(int i = 0;; i++){
        if(str[i] == '\0'){
            return change;
        }
        if(str[i] >= 97 && str[i] <= 122){
            if(str[i] == 122){
                str[i] = 97;
                change++;
            }
            else{
                str[i] = str[i]+1;
                change++;
            }
        }
    }
    return change;

}

// This function takes in an input string and determines the following:
// 1. The length of the string
// 2. the number of capital letters
// 3. the number of lowercase letters
// These values are placed into the 'string_stat' structure and this structure
// is returned.
// All test strings will be properly null terminated 
// A copy of the structure from midterm.h for your reference:
// typedef struct {
//     int length;
//     int caps;
//     int lower;
// } string_stat;
// See comment at top of file
// You may not use functions like islpha, strlen, toupper, etc.
string_stat get_stats(char str[]) {

    int length = 0;
    int lowers = 0;
    int uppers = 0;

    string_stat attr = {0,0,0};
    for(int i = 0;; i++){

        if(str[i] == '\0'){
            break;
        }
        if(str[i] >= 97 && str[i] <= 122){
            //lowercase
            lowers++;

        }
        if(str[i] >= 65 && str[i] <= 90){
            //uppercase
            uppers++;
        }
        length++;
    }

    attr.length = length;
    attr.caps = uppers;
    attr.lower = lowers;



    return attr;

}

int main() {

    return test();

}
