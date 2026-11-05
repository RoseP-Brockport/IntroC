#ifndef RECIPES_H
#define RECIPES_H

typedef struct Recipe {
    const char* result;
    const char* ingredient_a;
    int amount_a;
    const char* ingredient_b;
    int amount_b;
} Recipe;

extern const Recipe* recipe_find(const char* target);

#endif 