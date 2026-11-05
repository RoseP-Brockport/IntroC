/* Comprehensive crafting tests using the real inventory and recipes modules. */
#include "inventory.h"
#include "crafting.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("Crafting: unknown recipe and insufficient materials");
    Inventory *inv = inventory_create();
    assert(craft_item(inv, "unknown") == 0);
    assert(craft_item(inv, "healing_potion") == 0);
    inventory_add(inv, "herb", 3);
    assert(craft_item(inv, "healing_potion") == 0);
    assert(inventory_get_quantity(inv, "herb") == 3);
    inventory_add(inv, "water", 1);
    assert(craft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "herb") == 1);
    assert(inventory_get_quantity(inv, "water") == 0);
    inventory_destroy(inv);

    puts("Crafting: all six recipes with exactly enough ingredients");
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
        inv = inventory_create();
        inventory_add(inv, first[i], first_amount[i]);
        inventory_add(inv, second[i], second_amount[i]);
        assert(craft_item(inv, results[i]) == 1);
        assert(inventory_get_quantity(inv, results[i]) == 1);
        assert(inventory_get_quantity(inv, first[i]) == 0);
        assert(inventory_get_quantity(inv, second[i]) == 0);
        assert(inv->size == 1);
        inventory_destroy(inv);
    }

    puts("Crafting: failed recipe does not consume any ingredients");
    inv = inventory_create();
    inventory_add(inv, "herb", 10);
    inventory_add(inv, "water", 1);
    inventory_add(inv, "crystal", 2);
    size_t before = inv->size;
    assert(craft_item(inv, "mana_potion") == 0); /* one water short */
    assert(inv->size == before);
    assert(inventory_get_quantity(inv, "crystal") == 2);
    assert(inventory_get_quantity(inv, "water") == 1);
    assert(inventory_get_quantity(inv, "herb") == 10);
    assert(craft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);
    inventory_destroy(inv);

    puts("Crafting: multi-step manual crafting and resizing");
    inv = inventory_create();
    inventory_add(inv, "herb", 4);
    inventory_add(inv, "water", 6);
    inventory_add(inv, "crystal", 2);
    inventory_add(inv, "gold", 1);
    assert(inv->capacity == 11);
    for (int i = 0; i < 2; i++) {
        assert(craft_item(inv, "healing_potion") == 1);
        assert(craft_item(inv, "mana_potion") == 1);
        assert(craft_item(inv, "elixir") == 1);
    }
    assert(inventory_get_quantity(inv, "elixir") == 2);
    assert(craft_item(inv, "greater_elixir") == 1);
    assert(inv->size == 1);
    assert(inventory_get_quantity(inv, "greater_elixir") == 1);
    inventory_destroy(inv);

    puts("Crafting: a new output can trigger resizing");
    inv = inventory_create();
    inventory_add(inv, "herb", 3);
    inventory_add(inv, "water", 4);
    inventory_add(inv, "iron", 2);
    assert(inv->capacity == 5 && inv->size == 3);
    assert(craft_item(inv, "healing_potion") == 1);
    assert(inv->capacity == 11 && inv->size == 4);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);
    inventory_destroy(inv);
    puts("PASS: crafting component");
    return 0;
}
