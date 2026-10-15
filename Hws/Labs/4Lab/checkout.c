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

    float total = 0;
    for(int i = 0; i < item_count; i++){
        printf("%25s @ %9.2f x %6d = %9.2f\n", order[i].name, order[i].price, order[i].quantity, order[i].price*order[i].quantity);
        total += order[i].price*order[i].quantity;
    }
    printf("Total Price of Purchase:%9.2f\n",total);
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
    // initialize array full of termination characters
    char temp[NAME_LIMIT+1] = {'\0'};
    int seg = 1;
    int limit;
    for(int i = 0; i < (int)strlen(new_line.data); i++){
        // going to have name,quan,price - 
        //have to check if comma, 
        // if comma go from name -> quantity or quantity -> price




        //the logic here is awful and i had to troubleshoot it im sorry
        switch (seg)
        {
        case 1:
            if(new_line.data[i] == ','){
                strcpy(new_item.name, temp);
                for(int y = 0; y < i; y++){
                    temp[y] = '\0';
                }
                seg++;
                break;
            }
            temp[i] = new_line.data[i];
            break;
        case 2:
            if(new_line.data[i] == ','){
                new_item.quantity = atoi(temp);
                limit = strlen(temp);
            for(int y = 0; y < i-(int)strlen(new_item.name)-1; y++){
                temp[y] = '\0';
            }
            seg++;
            break;
            }
            
            temp[i-((int)strlen(new_item.name))-1] = new_line.data[i];
            break;
        case 3:
            if(new_line.data[i] == '\n' || new_line.data[i] == EOF){
                new_item.price = atof(temp);
                // dont need to clear array because we are done
                seg++;
                break;
            }
            temp[i-((int)strlen(new_item.name))-1-(int)limit-1] = new_line.data[i];
            break;
        default:
            break;
        }
    }
    new_item.price = atof(temp);


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
   for(int i = 0; i < (int)sizeof(new_line.data); i++){
    char ch = getchar();
    if(ch == EOF){
        new_line.last_line = TRUE;
        new_line.data[i] = '\0';
        break;
    }
    if(ch == '\n'){
        new_line.data[i] = '\0';
        break;
    }
    else{
        new_line.data[i] = ch;
    }


   }
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

