#include <stdlib.h>
#include <stdio.h>

#include "filter.h"

int main() {

    int original_list[MAX_ELEMENTS];

    //have to make array here, cant think of way to put it in filter.c
    int to_array[MAX_ELEMENTS];
    // This loop populates the array with consistent numbers
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        original_list[i] = (i * 37) % 100;
    }

    print_array(original_list);
    filter_evens(original_list,to_array);
    filter_odd_indexes(original_list,to_array);

}
