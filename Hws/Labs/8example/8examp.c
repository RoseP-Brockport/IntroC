#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int* ip = (int*) malloc(sizeof(int));
    *ip = 15;
    free(ip);

    
}