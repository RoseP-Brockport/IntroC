#include <stdlib.h>
#include <stdio.h>

#include "inventory.h"
#include "crafting.h"
#include "recipes.h"

/*
This function crafts the desired target product if possible.

1. If the recipe is not found, this function returns 0.
2. If the recipe is found, but there there are not
   sufficient items in the inventory to craft it,
   the inventory is not modified, and the function
   returns 0
3. If the recipe is found and the ingredients are
   present, both ingredients are consumed and 1 of
   the target products is added to the inventory,
   and the function returns 1

This function does not directly modify the inventory.
To modify the inventory call functions from inventory.c

@param inv A pointer to the inventory
@param target The string name of the product to craft

@return 0 on failure, 1 on success
*/
int craft_item(Inventory* inv, const char* target) {
    // TODO: Phase 3
    (void)inv;
    (void)target;
    return 0;
}
