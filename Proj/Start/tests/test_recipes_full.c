/* Read-only instructor recipe catalog. */
#include "recipes.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    const char *results[] = {
        "healing_potion", "mana_potion", "iron_sword",
        "magic_staff", "elixir", "greater_elixir"
    };
    const char *first[] = {
        "herb", "crystal", "iron", "wood", "healing_potion", "elixir"
    };
    const char *second[] = {
        "water", "water", "wood", "crystal", "mana_potion", "gold"
    };
    int first_amount[] = {2, 1, 3, 2, 1, 2};
    int second_amount[] = {1, 2, 1, 2, 1, 1};

    for (int i = 0; i < 6; i++) {
        const Recipe *recipe = recipe_find(results[i]);
        assert(recipe != NULL);
        assert(strcmp(recipe->result, results[i]) == 0);
        assert(strcmp(recipe->ingredient_a, first[i]) == 0);
        assert(strcmp(recipe->ingredient_b, second[i]) == 0);
        assert(recipe->amount_a == first_amount[i]);
        assert(recipe->amount_b == second_amount[i]);
    }
    assert(recipe_find("herb") == NULL);
    assert(recipe_find("unknown_recipe") == NULL);
    assert(recipe_find("Healing_Potion") == NULL);
    assert(recipe_find(NULL) == NULL);
    puts("PASS: recipes component");
    return 0;
}
