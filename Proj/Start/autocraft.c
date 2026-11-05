#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "inventory.h"
#include "crafting.h"
#include "autocraft.h"
#include "recipes.h"


/*
This function crafts a target by crafting all required materials first.
If this is not possible, no changes are made to the inventory and
0 is returned
If the full auto-crafting operation is possible, the crafting is handled
and 1 is returned.

@param inv A pointer to the inventory
@param target A pointer to the name of the desired final product
*/
int autocraft_item(Inventory* inv, const char* target) {
    // Optional extra credit. Leave this stub unchanged if not attempting it.
    (void)inv;
    (void)target;
    return 0;
}
