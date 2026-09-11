#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

/*
Given an input file, you are to count the number of lines, words, and characters present. 
Files will be provided to you via the ./program < file.txt
*/

// print error no argument specified and return 0 if no arg

//root@16b84e68b85f:/workspace/Lab2_219# ./pa < bport.txt

/*
format 

Total Lines: 6

Total Words: 48

Total Chars: 287

*/


// move forward
// if space, increment word
// if 'n increment, lines
// increment char always





    int lines = 0;
    int words = 0;
    int chars = 0;
    int last = 0;


    for (int ch; (ch = getchar()) != EOF;){


        chars += 1;
        if(last == ' '){
            if(ch == ' '){
            }
            else if (ch == '\n'){
                lines += 1;
            }
        }

        else if(last == '\n'){
            if(ch == ' '){
               
            }
            if(ch == '\n'){
                lines += 1;
                
            }
        }

        else if(ch == ' '){
            words += 1;
            
        }

        else if(ch == '\n'){
            lines += 1;
            
            words += 1;
        }
        

        last = ch;

/*
special cases

space after space
newline after space
space after newline
newline after newline
*/
        
    }
/*
args 

lines
words
chars
stats

*/

    if(argc == 1){
        printf("Error: No argument specified\n");
        return 0;
    }
    else if(argc != 0){
        if(strcmp(argv[1],"stats") == 0){
            printf("Total Lines: %d\nTotal Words: %d\nTotal Chars: %d\n",lines,words,chars);
        }
        else if(strcmp(argv[1],"lines") == 0){
            printf("Total Lines: %d\n", lines);
        }
        else if(strcmp(argv[1],"words") == 0){
            printf("Total Words: %d\n", words);
        }
        else if(strcmp(argv[1],"chars") == 0){
            printf("Total Chars: %d\n", chars);
        }
        else {
            printf("Total Lines: %d\nTotal Words: %d\nTotal Chars: %d\n",lines,words,chars);
        }
    }


    printf("\n");


}