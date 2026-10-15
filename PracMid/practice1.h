#ifndef PRACTICE_1_H
#define PRACTICE_1_H

typedef struct {
    int num_evens;
    int num_odds;
    int num_sevens;
} numerics;

extern int fix_bad_code( int *first, int *second );
extern int count_pairs(char sentence[]);
extern int swap_case(char sentence[]);
extern int last_occurence(char sentence[], char target);
extern int find_next_capital(char sentence[], int start_index);
numerics classify_digits(int data[]);

#endif