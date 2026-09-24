#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "checkout.h"

/*
This function prints out all items ordered in the following format

item_name @ price x quantity = total_cost
item_name @ price x quantity = total_cost
Total Price of Purchase: overall_total_cost

** The Spacing requirements are as follows **
Item names should be printed as %25s
Prices & totals should be printed as %9.2f 
Quantities should be printed as %6d

(see the writeup document for an example)
*/
void print_receipt(item order[], int item_count) {

    return;

}

/*
This function takes in a line struct and creates an item struct based on the
data contained in the line struct.\

@param new_line the line struct to be parsed into an item
@return an item struct populated with the data from the provided line
*/
item process_line(line new_line) {

    item new_item;
    return new_item;    

}

/*
This function reads a single line of input via the getchar() function.
It creates a line struct and fills the struct's data field with all the usable
text from the line (exlcuding new lines & the EOF special character).
If the line read ends with the EOF character, the struct's last_line element is
set to TRUE, otherwise, it is set to FALSE

@return a completed line struct including the content from one line of the csv
*/
line read_line() {

   line new_line;
   return new_line;

}

int main() {
    item order[MAX_ITEMS];
    int item_index = 0;
    line temp_line = {"",FALSE};
    while (!temp_line.last_line) {
        temp_line = read_line();
        if(temp_line.last_line) {
            break;
        }
        order[item_index] = process_line(temp_line);
        item_index++;
    }
    print_receipt(order, item_index);
    return 0;
}
