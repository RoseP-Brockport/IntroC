#ifndef CHECKOUT_H
#define CHECKOUT_H

#define NAME_LIMIT (25)
#define LINE_LIMIT (40)
#define MAX_ITEMS  (25)
#define TRUE (1)
#define FALSE (0)

typedef struct {
    char name[NAME_LIMIT + 1];
    int quantity;
    double price;
} item;

typedef struct {
    char data[LINE_LIMIT + 1];
    int last_line;
} line;

#endif 
