/* Comprehensive inventory tests; run after finishing Phase 2. */
#include "inventory.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    Inventory *inv = inventory_create();
    puts("Inventory: empty map and hash function");
    assert(hash_key("") == 0ULL);
    assert(hash_key("abc") == 294ULL);
    assert(hash_key("herb") == 417ULL);
    assert(inv->capacity == 5 && inv->size == 0);
    assert(inventory_get_quantity(inv, "missing") == 0);
    assert(inventory_remove(inv, "missing") == 0);
    assert(inventory_consume(inv, "missing", 1) == 0);

    puts("Inventory: copied strings and quantity changes");
    char name[] = "herb";
    inventory_add(inv, name, 5);
    Item *item = inventory_find(inv, "herb");
    assert(item != NULL && item->name != name);
    strcpy(name, "wood");
    assert(inventory_get_quantity(inv, "herb") == 5);
    inventory_add(inv, "herb", 7);
    assert(inv->size == 1 && inventory_find(inv, "herb") == item);
    assert(inventory_consume(inv, "herb", 13) == 0);
    assert(inventory_get_quantity(inv, "herb") == 12);
    assert(inventory_consume(inv, "herb", 4) == 1);
    assert(inventory_get_quantity(inv, "herb") == 8);
    assert(inventory_consume(inv, "herb", 8) == 1);
    assert(inv->size == 0);

    puts("Inventory: collision chain and deletion positions");
    inventory_add(inv, "a", 1);
    inventory_add(inv, "f", 2);
    inventory_add(inv, "k", 3);
    size_t index = (size_t)(hash_key("a") % inv->capacity);
    Item *head = inv->buckets[index];
    assert(head && head->next && head->next->next && !head->next->next->next);
    char first[32], middle[32], last[32];
    strcpy(first, head->name);
    strcpy(middle, head->next->name);
    strcpy(last, head->next->next->name);
    assert(inventory_remove(inv, middle) == 1);
    assert(inventory_remove(inv, first) == 1);
    assert(inventory_get_quantity(inv, last) > 0);
    assert(inventory_remove(inv, last) == 1);
    assert(inv->size == 0 && inv->buckets[index] == NULL);

    puts("Inventory: distinct keys with identical complete hash values");
    assert(hash_key("ab") == hash_key("ba"));
    inventory_add(inv, "ab", 8);
    inventory_add(inv, "ba", 12);
    assert(inv->size == 2);
    assert(inventory_get_quantity(inv, "ab") == 8);
    assert(inventory_get_quantity(inv, "ba") == 12);
    assert(inventory_remove(inv, "ab") == 1);
    assert(inventory_find(inv, "ab") == NULL);
    assert(inventory_get_quantity(inv, "ba") == 12);
    assert(inventory_remove(inv, "ba") == 1);
    assert(inv->size == 0);
    inventory_destroy(inv);

    puts("Inventory: resize at 4, 9, 18 and 36 items");
    inv = inventory_create();
    const char *keys[] = {
        "a","b","c","d","e","f","g","h","i","j",
        "k","l","m","n","o","p","q","r","s","t",
        "u","v","w","x","y","z","aa","ab","ac","ad",
        "ae","af","ag","ah","ai","aj","ak"
    };
    Item *first_node = NULL;
    for (int i = 0; i < 37; i++) {
        inventory_add(inv, keys[i], i + 1);
        if (i == 0) first_node = inventory_find(inv, "a");
        size_t expected = i < 3 ? 5u : i < 8 ? 11u : i < 17 ? 23u : i < 35 ? 47u : 95u;
        assert(inv->capacity == expected);
        assert(inv->size == (size_t)(i + 1));
        assert(inventory_find(inv, "a") == first_node);
    }
    for (int i = 0; i < 37; i++) {
        assert(inventory_get_quantity(inv, keys[i]) == i + 1);
    }

    puts("Inventory: every node is in its correct bucket");
    size_t counted = 0;
    for (size_t i = 0; i < inv->capacity; i++) {
        for (Item *node = inv->buckets[i]; node != NULL; node = node->next) {
            assert((size_t)(hash_key(node->name) % inv->capacity) == i);
            assert(++counted <= inv->size);
        }
    }
    assert(counted == inv->size);

    puts("Inventory: remove all items without shrinking");
    for (int i = 0; i < 37; i++) {
        assert(inventory_remove(inv, keys[i]) == 1);
    }
    assert(inv->size == 0 && inv->capacity == 95);
    inventory_resize(inv);
    assert(inv->capacity == 191 && inv->size == 0);
    inventory_print(inv); /* should display an empty inventory */
    inventory_destroy(inv);
    inventory_destroy(NULL);
    puts("PASS: inventory component");
    return 0;
}
