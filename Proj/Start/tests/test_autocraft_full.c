/* Optional Master Alchemist tests. Only run if implementing extra credit. */
#include "inventory.h"
#include "autocraft.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    puts("Bonus: unknown items cannot be autocrafted");
    Inventory *inv = inventory_create();
    assert(autocraft_item(inv, "herb") == 0);
    assert(autocraft_item(inv, "imaginary") == 0);
    inventory_destroy(inv);

    puts("Bonus: simple automatic recipe");
    inv = inventory_create();
    inventory_add(inv, "herb", 2);
    inventory_add(inv, "water", 1);
    assert(autocraft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 1);
    assert(inv->size == 1);
    inventory_destroy(inv);

    puts("Bonus: craft several layers of intermediate items");
    inv = inventory_create();
    inventory_add(inv, "herb", 4);
    inventory_add(inv, "water", 6);
    inventory_add(inv, "crystal", 2);
    inventory_add(inv, "gold", 1);
    assert(autocraft_item(inv, "greater_elixir") == 1);
    assert(inventory_get_quantity(inv, "greater_elixir") == 1);
    assert(inv->size == 1);
    inventory_destroy(inv);

    puts("Bonus: use intermediate items already in inventory");
    inv = inventory_create();
    inventory_add(inv, "elixir", 1);
    inventory_add(inv, "herb", 2);
    inventory_add(inv, "water", 3);
    inventory_add(inv, "crystal", 1);
    inventory_add(inv, "gold", 1);
    assert(autocraft_item(inv, "greater_elixir") == 1);
    assert(inv->size == 1);
    assert(inventory_get_quantity(inv, "greater_elixir") == 1);
    inventory_destroy(inv);

    puts("Bonus: existing final product must be increased");
    inv = inventory_create();
    inventory_add(inv, "healing_potion", 2);
    inventory_add(inv, "herb", 2);
    inventory_add(inv, "water", 1);
    assert(autocraft_item(inv, "healing_potion") == 1);
    assert(inventory_get_quantity(inv, "healing_potion") == 3);
    inventory_destroy(inv);

    puts("Bonus: missing ingredients must not modify inventory");
    inv = inventory_create();
    inventory_add(inv, "herb", 4);
    inventory_add(inv, "water", 5);
    inventory_add(inv, "crystal", 2);
    inventory_add(inv, "gold", 1);
    inventory_add(inv, "wood", 9);
    size_t old_size = inv->size;
    size_t old_capacity = inv->capacity;
    assert(autocraft_item(inv, "greater_elixir") == 0);
    assert(inv->size == old_size && inv->capacity == old_capacity);
    assert(inventory_get_quantity(inv, "herb") == 4);
    assert(inventory_get_quantity(inv, "water") == 5);
    assert(inventory_get_quantity(inv, "crystal") == 2);
    assert(inventory_get_quantity(inv, "gold") == 1);
    assert(inventory_get_quantity(inv, "wood") == 9);
    assert(inventory_get_quantity(inv, "elixir") == 0);
    inventory_destroy(inv);
    puts("PASS: bonus component");
    return 0;
}
