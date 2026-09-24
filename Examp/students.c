#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "students.h"

void change_name(struct student a, char new_name[]) {

    // naive approach to this apparently

    strcpy(a.name, new_name);
    return;

}

struct student fixed_changed_name(struct student a, char new_name[]) {

// structures do not get changed if you modify them elsewhere (modifying variable, not pointer iirc)

strcpy(a.name, new_name);
return a;

}

void change_name_arrays(char a_name[], char new_name[]){

strcpy(a_name, new_name);
return;

}