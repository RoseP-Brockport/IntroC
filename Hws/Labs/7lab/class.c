#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char bport[] = "Brockport";
    printf("%c\n",*bport);
    char *bp = bport;
    // bp++, netxhar in string
    // bp--, char before it in string
    // bp += sizeof(char) maybe works? idk twin

    bp++;
    printf("%s\n", bp);
    bp--;

    if(*bp) {

    }

    while(*bp){
        if(*bp == 'a'){
            // do something on a
        }
        bp++;
    }


    return 0;
}
