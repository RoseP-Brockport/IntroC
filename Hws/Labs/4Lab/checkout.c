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

    for(int i = 0; i < item_count; i++){
        //printf("%25s @ %9.2f x %6d = %9.2f\n", order[i].name, order[i].price, order[i].quantity, order[i].price*order[i].quantity);

        printf("%s,%d,%f\n", order[i].name, order[i].quantity, order[i].price);
    }
    return;

}

/*
This function takes in a line struct and creates an item struct based on the
data contained in the line struct.\

@param new_line the line struct to be parsed into an item
@return an item struct populated with the data from the provided line
*/
item process_line(line new_line) {

    // im so sorry for this  code, forgive me for i have sinned



    item new_item;
    char tempp[NAME_LIMIT];
    int segment = 0;
    int namelen;
    int quanlen;
    for(int i = 0; i < (int)strlen(new_line.data); i++){
        if(new_line.data[i] == ','){
            if(segment == 0){
                namelen = i;
                strcpy(new_item.name, tempp);
            }
            else if(segment == 1){
                quanlen = i-namelen-1;
                new_item.quantity = atoi(tempp);
            }
            for(int i = 0; i < (int)strlen(tempp); i++){
                tempp[i] = 0;
            }
            segment++;
            continue;
        }
        if(new_line.data[i] == '\n' || new_line.data[i] == EOF){
            new_item.price = atof(tempp);
            break;
        }

        switch (segment)
        {
        case 0:
            tempp[i] = new_line.data[i];
            break;
        case 1:
            tempp[i-namelen-2] = new_line.data[i];
            break;
        case 2:
            tempp[i-namelen-quanlen-3] = new_line.data[i];
            break;

        default:
            break;
        }

    }
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
   //set to false unless hits EOF which will make it true
   new_line.last_line = FALSE;

   // check eof, if eof, set last line true, break, if just \n then break, else, add to string
   for(int i = 0; i < (int)strlen(new_line.data); i++){
    char ch = getchar();
    if(ch == EOF){
        new_line.last_line = TRUE;
        break;
    }
    if(ch == '\n'){
        break;
    }
    else{
        new_line.data[i] = ch;
    }


   }
   printf("test %s test\n", new_line.data);
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

// /usr/bin/gcc -fdiagnostics-color=always -g /home/Blake/Documents/BrockY3S1/IntroC/Hws/Labs/4Lab/*.c -o /home/Blake/Documents/BrockY3S1/IntroC/Hws/Labs/4Lab/checkout -Wall -Wextra < /home/Blake/Documents/BrockY3S1/IntroC/Hws/Labs/4Lab/order1.csv