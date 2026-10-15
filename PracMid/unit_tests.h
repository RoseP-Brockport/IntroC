#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#define MAX_ARRAY (10)
#define MAX_STRING (100)
#define TRUE (1)
#define FALSE (0)

extern int assert_int_equal(char *name, int expected, int actual, int test_number);
extern int assert_double_equal(char* name, double expected, double actual, int test_number);
extern int int_array_equal(char* name, int expected[], int actual[], int size, int test_number);
extern int str_equal(char* name, char* expected, char* actual, int length, int test_number);
extern int test();

#endif 