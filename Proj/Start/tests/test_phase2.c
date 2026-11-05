/* Phase 2: collision handling, deletion, consumption, and resizing. */
#include "inventory.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    puts("Phase 2: linked-list collisions");
    Inventory *inv = inventory_create();
    /* a, f and k all hash to the same bucket when capacity is 5. */
    assert(hash_key("a") % 5 == hash_key("f") % 5);
    assert(hash_key("f") % 5 == hash_key("k") % 5);
    inventory_add(inv, "a", 1);
    inventory_add(inv, "f", 2);
    inventory_add(inv, "k", 3);
    assert(inv->capacity == 5 && inv->size == 3);
    assert(inventory_get_quantity(inv, "a") == 1);
    assert(inventory_get_quantity(inv, "f") == 2);
    assert(inventory_get_quantity(inv, "k") == 3);

    puts("Phase 2: delete from the middle, head, and tail");
    size_t bucket = (size_t)(hash_key("a") % inv->capacity);
    Item *head = inv->buckets[bucket];
    assert(head && head->next && head->next->next);
    assert(head->next->next->next == NULL);
    char first[32], middle[32], last[32];
    strcpy(first, head->name);
    strcpy(middle, head->next->name);
    strcpy(last, head->next->next->name);
    assert(inventory_remove(inv, middle) == 1);
    assert(inventory_remove(inv, first) == 1);
    assert(inventory_find(inv, last) != NULL);
    assert(inventory_remove(inv, last) == 1);
    assert(inv->size == 0);
    assert(inv->buckets[bucket] == NULL);
    assert(inventory_remove(inv, "not_here") == 0);

    puts("Phase 2: two different strings with the SAME hash");
    assert(hash_key("ab") == 195ULL);
    assert(hash_key("ab") == hash_key("ba"));
    inventory_add(inv, "ab", 4);
    inventory_add(inv, "ba", 7);
    assert(inv->size == 2);
    assert(inventory_get_quantity(inv, "ab") == 4);
    assert(inventory_get_quantity(inv, "ba") == 7);
    assert(inventory_remove(inv, "ab") == 1);
    assert(inventory_find(inv, "ab") == NULL);
    assert(inventory_get_quantity(inv, "ba") == 7);
    inventory_destroy(inv);

    puts("Phase 2: consume quantities and remove empty items");
    inv = inventory_create();
    inventory_add(inv, "herb", 5);
    assert(inventory_consume(inv, "herb", 2) == 1);
    assert(inventory_get_quantity(inv, "herb") == 3);
    assert(inventory_consume(inv, "herb", 4) == 0);
    assert(inventory_get_quantity(inv, "herb") == 3);
    assert(inventory_consume(inv, "herb", 3) == 1);
    assert(inventory_find(inv, "herb") == NULL);
    assert(inv->size == 0);
    inventory_destroy(inv);

    puts("Phase 2: automatic growth at 4 and 9 distinct items");
    inv = inventory_create();
    const char *names[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i"};
    for (int i = 0; i < 9; i++) {
        inventory_add(inv, names[i], i + 1);
        assert(inv->size == (size_t)(i + 1));
        assert(inv->capacity == (i < 3 ? 5u : i < 8 ? 11u : 23u));
    }
    for (int i = 0; i < 9; i++) {
        assert(inventory_get_quantity(inv, names[i]) == i + 1);
    }
    Item *original = inventory_find(inv, "a");
    inventory_resize(inv);
    assert(inv->capacity == 47);
    assert(inventory_find(inv, "a") == original); /* reuse nodes */
    assert(inv->size == 9);
    inventory_add(inv, "a", 10);
    assert(inv->size == 9 && inv->capacity == 47);
    assert(inventory_get_quantity(inv, "a") == 11);
    inventory_destroy(inv);
    inventory_destroy(NULL);
    puts("PASS: Phase 2");
    return 0;
}
