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
    // TODO: Phase 1
    return NULL;
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
    // TODO: Phase 1
    (void)key;
    return 0;
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
    // TODO: Phase 1; expand to handle collision chains in Phase 2
    (void)inv;
    (void)name;
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
    // TODO: Phase 1
    (void)inv;
    (void)name;
    return 0;
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
    // TODO: Phase 1; extend for collisions/resizing in Phase 2
    (void)inv;
    (void)name;
    (void)quantity;
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
    (void)inv;
    (void)name;
    (void)quantity;
    return 0;
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
    (void)inv;
    (void)name;
    return 0;
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
    (void)inv;
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
    (void)inv;
}