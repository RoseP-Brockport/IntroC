#ifndef MIDTERM_H
#define MIDTERM_H

typedef struct {
    int length;
    int caps;
    int lower;
} string_stat;

extern int fix_bad_code( int *first, int *second );
extern char preceding_char(char str[], char target);
extern int lower_rotate(char str[]);
extern string_stat get_stats(char str[]);

#endif