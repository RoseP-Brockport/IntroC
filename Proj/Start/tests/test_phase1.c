/* Phase 1: basic hashing, allocation, insertion and lookup.
   These tests deliberately use no collisions or resizing.
   inventory_destroy() is not required until Phase 2. */
#include "inventory.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    puts("Phase 1: hash function");
    assert(hash_key("") == 0ULL);
    assert(hash_key("a") == 97ULL);
    assert(hash_key("abc") == 294ULL);
    assert(hash_key("herb") == 417ULL);
    /* Character order does not affect an additive hash. */
    assert(hash_key("ab") == hash_key("ba"));

    puts("Phase 1: create the inventory");
    Inventory *inv = inventory_create();
    assert(inv != NULL);
    assert(inv->size == 0);
    assert(inv->capacity == 5);
    assert(inv->buckets != NULL);
    for (size_t i = 0; i < inv->capacity; i++) {
        assert(inv->buckets[i] == NULL);
    }
    assert(inventory_find(inv, "missing") == NULL);
    assert(inventory_get_quantity(inv, "missing") == 0);

    puts("Phase 1: add three items (different buckets)");
    /* At capacity 5, a, b, c have different bucket indices. */
    inventory_add(inv, "a", 2);
    inventory_add(inv, "b", 4);
    inventory_add(inv, "c", 6);
    assert(inv->size == 3);
    assert(inv->capacity == 5);
    assert(inventory_get_quantity(inv, "a") == 2);
    assert(inventory_get_quantity(inv, "b") == 4);
    assert(inventory_get_quantity(inv, "c") == 6);

    puts("Phase 1: update an existing item");
    inventory_add(inv, "b", 3);
    assert(inv->size == 3);
    assert(inv->capacity == 5);
    assert(inventory_get_quantity(inv, "b") == 7);

    puts("Phase 1: make an independent copy of the name");
    char name[] = "b";
    Item *entry = inventory_find(inv, name);
    assert(entry != NULL);
    assert(strcmp(entry->name, "b") == 0);
    assert(entry->name != name);
    name[0] = 'x';
    assert(inventory_get_quantity(inv, "b") == 7);

    /* Cleanup will be added in Phase 2. */
    puts("PASS: Phase 1");
    return 0;
}
