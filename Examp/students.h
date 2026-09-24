#ifndef STUDENTS_H
#define STUDENTS_H

#define MAX_NAME (20)
struct student {
    char name[MAX_NAME+1];
    float gpa;
    int semester;

};

extern void change_name(struct student a, char new_name[]);
extern struct student fixed_changed_name(struct student a, char new_name[]);
extern void change_name_arrays(char a_name[], char new_name[]);

// this is a header, made by brandon

#endif


