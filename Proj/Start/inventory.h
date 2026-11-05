#ifndef INVENTORY_H
#define INVENTORY_H

#define INITIAL_BUCKETS (5)

typedef struct Item {
    char* name;
    int quantity;
    struct Item* next;
} Item;

typedef struct Inventory{
    Item** buckets;
    unsigned int size;
    unsigned int capacity;
} Inventory;

extern Inventory* inventory_create(void);
extern long long unsigned int hash_key(const char* key);
extern Item* inventory_find(Inventory* inv, const char* name);
extern int inventory_get_quantity(Inventory* inv, const char* name);
extern void inventory_add(Inventory* inv, const char* name, int quantity);
extern int inventory_consume(Inventory* inv, const char* name, int quantity);
extern int inventory_remove(Inventory* inv, const char* name);
extern void inventory_resize(Inventory* inv);
extern void inventory_print(const Inventory* inv);
extern void inventory_destroy(Inventory* inv);

#endif