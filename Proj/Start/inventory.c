#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "inventory.h"

/*
Allocates space for the inventory and returns a pointer to it
Space should be allocated for INITIAL_BUCKETS elements in the array.
Sets size to 0 and capacity to INITIAL_BUCKETS

@return a pointer to a new allocated and configured inventory
*/
Inventory* inventory_create(void) {
    

    //inventory has buckets, size, capacity
    Inventory* inventory = calloc(1, sizeof(Inventory));
    Item** buckets = calloc(INITIAL_BUCKETS, sizeof(Item*));
    inventory->buckets = buckets;
    inventory->size = 0;
    inventory->capacity = INITIAL_BUCKETS;

    return inventory;
}

/*
This function performs a simple hash function on the key
and returns the result.

To hash, add the ascii value of each character together

for example, "Hello" would hash with
72 + 101 + 108 + 108 + 111

@param key a pointer to the string to hash
@return the hash digest (sum of all ascii values)
*/
long long unsigned int hash_key(const char* key) {

    unsigned long long int hash = 0;
    while(*key != '\0'){
        hash += *key;
        key++;
    }
    return hash;
}

/*
This function locates the Item matching the name within
the inventory

If it is not found, NULL is returned. If the item is
present, a pointer to the entry is returned.

In Phase 1, this can simply check the index in the buckets
array.
In Part 2, you may need to navigate a Linked List to locate
the item

@param inv a pointer to the inventory
@param name a pointer to the desired item's name

@return a pointer to the desired item
*/
Item* inventory_find(Inventory* inv, const char* name) {
    // TODO: expand to handle collision chains in Phase 2

    // if is found no collison
    Item* item = inv->buckets[hash_key(name)%inv->capacity];
    while(item != NULL){
        if(strcmp(item->name, name) == 0){
            return item;
        }
            item = item->next;
    }
    return NULL;

}

/*
This function returns the current quantity of the desired item.
If the item is not found, 0 is returned.

@param inv A pointer to the inventory
@param name A pointer to the string name of the desired item

@return the integer quantity of the item in the inventory
*/
int inventory_get_quantity(Inventory* inv, const char* name) {
    
    Item* item = inventory_find(inv, name);
    if(item != NULL){
        return item->quantity;
    }
    else{
        return NULL;
    }
}

/*
This function adds an item to the hashmap. If the item is already
in the map, it adds the new quantity to the existing quantity.
If the item is not found it:
    1. Allocates space for a new item
    2. Allocates space for the name of the new item
    3. configures the item with the provided values
    4. Sets the Item's next to NULL
    5. Adds 1 to the size
    6. Resizes the hashmap if needed (Size / Capacity >= 0.75)
       This is done before adding a new key.
    7. Adds a pointer to the new item to the hashmap

In Phase 1, you do not need to do step 6.
In Phase 1, step 7 only needs to place the item into the buckets array
In Phase 2, step 6 will need completed, and adding the entry
will require navigating the linked list structure to identify
the proper place to add the pointer.

@param inv A pointer to the inventory
@param name A pointer to the string name of the Item
@param quantity The amount to increase the quantity by
*/
void inventory_add(Inventory* inv, const char* name, int quantity) {
    // TODO: extend for collisions/resizing in Phase 2

    // NEW: If adding a new element to the hash map would make entries/capacity > 0.75, call resize, resize should be performed before attempting to add entry.
    
    if(inv->size != 0){
        if(inventory_find(inv, name) == NULL){
            if(((double)inv->size/ (double)inv->capacity) >= 0.75){
                inventory_resize(inv);
            }
        }
    }

    if(inv->buckets[hash_key(name)%inv->capacity] == NULL){
        Item* newItem = (Item*)calloc(1, sizeof(Item));
        newItem->name = calloc(strlen(name)+1, sizeof(char));
        strcpy(newItem->name, name);
        newItem->quantity = quantity;
        newItem->next = NULL;
        inv->buckets[hash_key(name)%inv->capacity] = newItem;
        inv->size++;
    }
    else{
        Item* search = inv->buckets[hash_key(name)%inv->capacity];
        while(1){
           
            if(strcmp(search->name, name) == 0){
                search->quantity += quantity;
                break;
            }
            else if(search->next == NULL){
                Item* newItem = (Item*)calloc(1, sizeof(Item));
                newItem->name = calloc(strlen(name)+1, sizeof(char));
                strcpy(newItem->name, name);
                newItem->quantity = quantity;
                newItem->next = NULL;
                search->next = newItem;
                inv->size++;
                break;
            }
            else{
                search = search->next;
            }
        }
        
        
        //inv->buckets[hash_key(name)]->quantity += quantity;
    }

    // check if current->name == name,
    // if not, go to current->next, then check again, until found or current->next == null,
    // if hit current->next == null, then make new item for this
}


/*
This function consumes a quantity of an item from the hash map.
If the item is not found or the quantity available is less
than the quantity requested, 0 is returned.
Otherwise, the quantity is reduced by the given amount.
If the amount is reduced to 0, the item is removed entirely
from the inventory.
1 is returned if the quantity is reduced or the item removed.

@param inv A pointer to the inventory
@param name A pointer to the name of the Item
@param quantity the number to reduce the quantity by

@return 1 if the item's quantity is successfully reduced, 0 otherwise
*/
int inventory_consume(Inventory* inv, const char* name, int quantity) {
    // TODO: Phase 2
    
    if(inventory_find(inv, name) == NULL){
        return 0;
    }
    if (inventory_find(inv, name)->quantity > 1){
        inventory_find(inv, name)->quantity -= 1;
        return 1;
    }
    else{
        inventory_remove(inv, name);
        return 1;
    }
}

/*
This function removes the Item with the given name from the hashmap.
If the item is successfully removed, return 1, otherwise return 0.
Notes:
    1. Be careful to free up any memory related to the Item
    2. If the index you are removing from is chained, move pointers
       such that no items are lost
    3. If you remove the only entry at an index, set the index
       in buckets to NULL

@param inv A pointer to the inventory
@param name A pointer to the name to remove
@return 1 if an item is removed, 0 otherwise
*/
int inventory_remove(Inventory* inv, const char* name) {
    // TODO: Phase 2
    
    Item* current = inv->buckets[hash_key(name)%inv->capacity];
    Item* prev;
    while(1){
        if(strcmp(current->name, name) == 0){
            if(strcmp(inv->buckets[hash_key(name)%inv->capacity]->name, name) == 0){
                inv->buckets[hash_key(name)%inv->capacity] = current->next;
                free(current);
                inv->size -= 1;
                return 1;
            }
            else{
                prev->next = current->next;
                free(current);
                inv->size -= 1;
                return 1;
            }
        }
        else if(current->next != NULL){
            prev = current;
            current = current->next;
        }
        else{
            return 0;
        }
    }
}

/*
This function resizes the hashmap when size / capacity >= 0.75
This check is performed in inventory_add before a new key is added
It increases capacity with the following: (capacity * 2) + 1

Notes:
    1. You will need to allocate an entirely buckets array
    2. You will need to iterate through all Items and place
       them in a new location based on their new hash % capacity.
    3. Don't forget to free up the old buckets array

@param inv A pointer to the inventory
*/
void inventory_resize(Inventory* inv) {
    // TODO: Phase 2
    // todo, e.g. "AAAAAAAAA"
    // if our hash collisions are handled by making it a linked list, then uh, dont we not need to increase the size of the hashmap?,
    // i blindly followed implementation, i fixed this by adding %inv->capacity

    //this is called when we know we have to resize, 
    // to make this easy, iterate through the inventory and add all elements to a stack,
    // then pop elements off the top and add them to the new buckets?
    // good first plan ig sure
    Item** newBuckets = calloc((inv->capacity*2)+1, sizeof(Item));
    int newCap = (inv->capacity*2)+1;
    // order of what is in the linked list for a collision doesnt matter i think, therefore,  can just make a linked list out of everything and then add it to new one ig?
    // have to do this and not just transplant the existing linked lists because for x%z = y%z , x%a doesnt have to = y%a. 
    // i am gonna iterate on the current list and connect everything together i think

    // pseudo
    // iterate over buckets, if current bucket not null, connect previous non empty bucket item.next to point to this item
    int i = 0;
    Item* listOne;
    Item* prev;
    for(i = 0; i < inv->size; i++){
        if(inv->buckets[i] != NULL){
            Item* temp = inv->buckets[i];
            while(1){
                if(temp->next != NULL){
                    temp = temp->next;
                }
                else{
                    listOne = temp;
                    break;
                }
            }
            i++;
            break;
        }
    }
    prev = listOne;

    for(int i = 1; i < inv->size; i++){
        if(inv->buckets[i] != NULL){
            prev->next = inv->buckets[i];
            while(1){
                if(inv->buckets[i]->next != NULL){
                    inv->buckets[i] = inv->buckets[i]->next;
                }
                else{
                    prev = inv->buckets[i];
                    break;
                }

            }
        }
    }
    // we should now have a linked list of every object in this inventory,,, with listOne being the first item at the start
    // i should be executed for whatever this code is ngl, idk why, it feels, dirty, impure even.

    // this feels cursed but i no longer need this
    free(inv->buckets);
    inv->buckets = newBuckets;
    
    // prev will be copy of list to free it, i realize now that since i am using .next to connect everything, i either need to work around that, or make new items to put into the buckets
    prev = listOne;
    inv->size = 0;
    inv->capacity = newCap;
    while(prev->next != NULL){
        
        inventory_add(inv, listOne->name, listOne->quantity);
        prev = prev->next;
    }

    // ts genuinely so fucked

    // now freeing all old items...
    while(listOne->next != NULL){
        prev = listOne->next;
        free(listOne);
        listOne = prev;
    }
    
    // this was actually horrific i am sorry to myself

}


/*
This function prints the inventory.
If nothing is in the inventory it prints: "Inventory is empty."
Otherwise, it prints every item (In any order) in the format:
"Name: Quantity"
One item per line.

@param inv A pointer to the inventory
*/
void inventory_print(const Inventory* inv) {
    // TODO: Phase 3
    (void)inv;
}

/*
This function completely deletes and frees up all related memory.

@param inv A pointer to the inventory to free up.
*/
void inventory_destroy(Inventory* inv) {
    // TODO: Phase 2
    // kinda funny i basically did this for my resize, can probabbbly copy most of the code from there
    
    //copied from resize
    int i = 0;
    Item* listOne;
    Item* prev;
    for(i = 0; i < inv->size; i++){
        if(inv->buckets[i] != NULL){
            Item* temp = inv->buckets[i];
            while(1){
                if(temp->next != NULL){
                    temp = temp->next;
                }
                else{
                    listOne = temp;
                    break;
                }
            }
            i++;
            break;
        }
    }
    prev = listOne;

    for(int i = 1; i < inv->size; i++){
        if(inv->buckets[i] != NULL){
            prev->next = inv->buckets[i];
            while(1){
                if(inv->buckets[i]->next != NULL){
                    inv->buckets[i] = inv->buckets[i]->next;
                }
                else{
                    prev = inv->buckets[i];
                    break;
                }

            }
        }
    }
    while(listOne != NULL){
        prev = listOne->next;
        free(listOne);
        listOne = prev;
    }
    free(inv->buckets);
    free(inv);
}