#ifndef PROCESSOR_H
#define PROCESSOR_H

extern char* find_substring(char *text, char *target);
extern char* find_field(char *text, char *field);
extern void terminate_field(char *text);
extern void process(char *data, char *fields[], char *results[], int c);

#endif