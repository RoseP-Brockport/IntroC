/* Phase 3: crafting. The command loop is tested with redirected input. */
#include "inventory.h"
#include "crafting.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    Inventory *inv = inventory_create();
    puts("Phase 3: craft a healing potion");
    inventory_add(inv, "herb", 4);
    inventory_add(inv, "water", 2);
    assert(craft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "herb") == 2);
    assert(inventory_get_quantity(inv, "water") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);

    puts("Phase 3: craft again and remove exhausted ingredients");
    assert(craft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 2);
    assert(inventory_find(inv, "herb") == NULL);
    assert(inventory_find(inv, "water") == NULL);

    puts("Phase 3: failed crafting does not change anything");
    size_t size_before = inv->size;
    size_t capacity_before = inv->capacity;
    assert(craft_item(inv, "healing_potion") == 0);
    assert(craft_item(inv, "unknown_item") == 0);
    assert(inv->size == size_before);
    assert(inv->capacity == capacity_before);
    assert(inventory_get_quantity(inv, "healing_potion") == 2);

    puts("Phase 3: craft an item from other crafted items");
    inventory_add(inv, "crystal", 1);
    inventory_add(inv, "water", 2);
    assert(craft_item(inv, "mana_potion") == 1);
    assert(craft_item(inv, "elixir") == 1);
    assert(inventory_get_quantity(inv, "elixir") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);

    puts("Phase 3: print inventory (visual check)");
    inventory_print(inv);
    inventory_destroy(inv);
    puts("PASS: Phase 3");
    return 0;
}
