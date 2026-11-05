#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "recipes.h"

/*
Constant consisting of the recipes supported by the system
Result_name, item_1, item_1_quantity, item_2, item_2_quantity
*/
static const Recipe RECIPES[] = {
    {"healing_potion", "herb",           2, "water",       1},
    {"mana_potion",    "crystal",        1, "water",       2},
    {"iron_sword",     "iron",           3, "wood",        1},
    {"magic_staff",    "wood",           2, "crystal",     2},
    {"elixir",         "healing_potion", 1, "mana_potion", 1},
    {"greater_elixir", "elixir",         2, "gold",        1}
};

/*
This function takes in the name of the item to be crafted and returns a
pointer to the recipe used to craft the item. If the recipe is not known,
NULL is returned.

@param target string representation of the desired crafting product
@return a constant pointer to the recipe object for the desired product
*/
const Recipe* recipe_find(const char* target) {

    if (target == NULL) {
        return NULL;
    }
    const size_t count = sizeof(RECIPES) / sizeof(RECIPES[0]);
    for (size_t i = 0; i < count; ++i) {
        if (strcmp(RECIPES[i].result, target) == 0) {
            return &RECIPES[i];
        }
    }
    return NULL;

}