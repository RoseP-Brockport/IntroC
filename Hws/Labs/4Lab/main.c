#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./students.h"

int main(int argc, char const *argv[])
{


    struct student alice, bob;
    struct student charlie = {"Charlie",3.6,7};

    alice.gpa = 2.5;
    alice.semester = 5;

    strcpy(alice.name, "Alice");


    bob = alice;
    // deep copy, they become two separate things, bob would be separate from alice.

    printf("Bob's Name before change %s\n", bob.name);

    change_name(bob, "Robert");
    printf("Bob's Name after change_name: %s\n", bob.name);
    
    bob = fixed_changed_name(bob, "Bobert");
    printf("Bob's Name after change_name: %s\n", bob.name);


    change_name_arrays(bob.name, "Rob");
    printf("Bob's Name after change_name: %s\n", bob.name);
}
