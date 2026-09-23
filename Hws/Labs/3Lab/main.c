#include <stdlib.h>
#include <stdio.h>

#include "filter.h"

int main() {

    int original_list[MAX_ELEMENTS];

    // This loop populates the array with consistent numbers
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        original_list[i] = (i * 37) % 100;
    }

    

}
