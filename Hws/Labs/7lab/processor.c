#include <stdlib.h>
#include <stdio.h>

#include "processor.h"

/*
This function takes two strings. The first being a larger string, and the
second string being a target subtstring to locate within the first string.
This function returns a pointer to the first character of the 
located substring. If the substring is not found, NULL is returned.

You may not use Bracket Syntax to navigate the strings/arrays.

@param text the text to search for the substring
@param target the substring to find in text

@return a pointer to the start of the substring in text
*/
char* find_substring(char *text, char *target) {

    //if first char of target, check length of target and check if found, make sure not to go over index
    char* tcpy = target;
    char tfirst = *target;
    char* texcpy = text;
    int tlen = 0;
    int texlen = 0;
    while(*text != '\0'){
        texcpy++;
        texlen++;
    }
    while(*tcpy != '\0'){
        tcpy++;
        tlen++;
    }

    // mmm i dont wanan make sure im not outta bounds so we hit a lil trick callled lmao xd 
    while(*(text+tlen) != '\0'){
        if(*text == tfirst){
            for(int i = 1; i <= tlen; i++){
                if(*(target+i) == *(text+i)){
                    if(i = tlen){
                        return text;
                    }
                    continue;
                }
                else{break;}

            }
        }
        text++;
    }


    return NULL;
}

/*
This function, provided the larger set of text locates the specified field
with the help of find_substring. 
This function calls substring repeatedly until a perfect match
for the field is found. A perfect match is
1. Either at the front of the string or preceeded by a ;
2. Ended with an equal sign.

You may not use Bracket Syntax to navigate the strings/arrays.

@param text the full set of text to find the data in
@param field the field to extract data for 

@return a pointer to the start of the field data (after the equal sign)
*/
char* find_field(char *text, char *field) {
    // this is evil why would you make me do this :(
    

    return NULL;

}

/*
This function takes a string of text and replaces the first occurence of a
semicolon with a null terminator to end a field.

You may not use Bracket Syntax to navigate the strings/arrays.

@param text the text to modify.
*/
void terminate_field(char *text) {
    
    return;

}

/*
This function handles the data organization process. 
If c is 0, it does nothing
Otherwise, it locates and extracts data from the fields, terminates
each substring with a null terminator, and places pointers to the 
start of each result in the results array in an order matching that 
of the fields array.

You may use bracket syntax for this function.

@param data The large string of text containing required data
@param fields The list of fields we need to collect
@param results The array of pointers where we will store results
@param c The number of fields being requested
*/
void process(char *data, char *fields[], char *results[], int c) {

    return;
    
}