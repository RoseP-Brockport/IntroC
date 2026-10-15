#include <stdlib.h>
#include <stdio.h>

#include "unit_tests.h"
#include "midterm.h"

int assert_int_equal(char *name, int expected, int actual, int test_number) {

    if (expected == actual) {
        printf("[PASS] Test %d: %s\n", test_number, name);
        return TRUE;
    }
    printf("[FAIL] Test %d: %s\n", test_number, name);
    printf("\tExpected: %d\n", expected);
    printf("\tActual:   %d\n", actual);
    return FALSE;

}

int assert_double_equal(char* name, double expected, double actual, int test_number) {

    if (expected == actual) {
        printf("[PASS] Test %d: %s\n", test_number, name);
        return TRUE;
    }
    printf("[FAIL] Test %d: %s\n", test_number, name);
    printf("\tExpected: %f\n", expected);
    printf("\tActual:   %f\n", actual);
    return FALSE;

}

int int_array_equal(char* name, int expected[], int actual[], int size, int test_number) {
    int passed = TRUE;
    for (int i = 0; i < size; i++) {
        if (expected[i] != actual[i]) {
            if (passed) {
                passed = FALSE;
                printf("[FAIL] Test %d: %s\n", test_number, name);
            }
            printf("\tIndex %i: Expected %d, got %d\n", i, expected[i], actual[i]);
        }
    }
    if (passed) {
        printf("[PASS] Test %d: %s\n", test_number, name);
    }
    return passed;
}

int str_equal(char* name, char* expected, char* actual, int length, int test_number) {
    int passed = TRUE;
    for (int i = 0; i < length; i++) {
        if (expected[i] != actual[i]) {
            if (passed) {
                passed = FALSE;
                printf("[FAIL] Test %d: %s\n", test_number, name);
            }
            printf("\tIndex %i: Expected %c, got %c\n", i, expected[i], actual[i]);
        }   
    }
    if (passed) {
        printf("[PASS] Test %d: %s\n", test_number, name);
    }
    return passed;
}

int test() {
    int fc = 0;
    int tr = 0;

     printf("\n===== fix_bad_code =====\n");
    {
        int first = 9;
        int second = 3;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("first larger: return", 1, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("first larger: first decreases",
                              8, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("first larger: second increases",
                              4, second, tr)) {
            fc++;
        }
    }
    {
        int first = 2;
        int second = 6;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("first smaller: return", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("first smaller: first unchanged",
                              2, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("first smaller: second unchanged",
                              6, second, tr)) {
            fc++;
        }
    }
    {
        int first = 4;
        int second = 4;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("equal values: return", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("equal values: first unchanged",
                              4, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("equal values: second unchanged",
                              4, second, tr)) {
            fc++;
        }
    }
    {
        int first = -2;
        int second = -5;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("negative values: return", 1, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("negative values: first decreases",
                              -3, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("negative values: second increases",
                              -4, second, tr)) {
            fc++;
        }
    }
    {
        int first = 0;
        int second = -1;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("zero greater than negative: return",
                              1, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("zero greater than negative: first",
                              -1, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("zero greater than negative: second",
                              0, second, tr)) {
            fc++;
        }
    }

    printf("\n===== preceding_char =====\n");
    {
        char sentence[] = "";
        tr++;
        if (!assert_int_equal("empty string", '?',
                              preceding_char(sentence, 'x'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "hello";
        tr++;
        if (!assert_int_equal("target absent", '?',
                              preceding_char(sentence, 'x'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "hello";
        tr++;
        if (!assert_int_equal("target at start", '?',
                              preceding_char(sentence, 'h'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "hello";
        tr++;
        if (!assert_int_equal("first of repeated targets", 'e',
                              preceding_char(sentence, 'l'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "banana";
        tr++;
        if (!assert_int_equal("first occurrence in word", 'b',
                              preceding_char(sentence, 'a'), tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("search does not change input", "banana",
                       sentence, sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "abc";
        tr++;
        if (!assert_int_equal("target at end", 'b',
                              preceding_char(sentence, 'c'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = " hi";
        tr++;
        if (!assert_int_equal("preceding character is space", ' ',
                              preceding_char(sentence, 'h'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "z";
        tr++;
        if (!assert_int_equal("single-character string", '?',
                              preceding_char(sentence, 'z'), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "abac";
        tr++;
        if (!assert_int_equal("repeated target at start", '?',
                            preceding_char(sentence, 'a'), tr)) {
            fc++;
    }
}

    printf("\n===== lower_rotate =====\n");
    {
        char sentence[] = "";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("empty string: count", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("empty string: output", "", sentence,
                       sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "xyz";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("alphabet wrap: count", 3, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("alphabet wrap: output", "yza", sentence,
                       sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "BrOcKpOrT";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("mixed case: count", 4, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("mixed case: output", "BsOdKqOsT", sentence,
                       sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "abcD1";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("lowercase with nonletters: count",
                              3, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("lowercase with nonletters: output", "bcdD1",
                       sentence, sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "AZ 09!z";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("uppercase, symbols and z: count",
                              1, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("uppercase, symbols and z: output", "AZ 09!a",
                       sentence, sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "ABC 123!?";
        int result = lower_rotate(sentence);

        tr++;
        if (!assert_int_equal("no lowercase: count", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("no lowercase: unchanged", "ABC 123!?",
                    sentence, sizeof(sentence), tr)) {
            fc++;
        }
}

    printf("\n===== get_stats =====\n");
    {
        char sentence[] = "";
        string_stat result = get_stats(sentence);

        tr++;
        if (!assert_int_equal("empty: length", 0, result.length, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("empty: capitals", 0, result.caps, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("empty: lowercase", 0, result.lower, tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "HELLO";
        string_stat result = get_stats(sentence);

        tr++;
        if (!assert_int_equal("uppercase only: length",
                              5, result.length, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("uppercase only: capitals",
                              5, result.caps, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("uppercase only: lowercase",
                              0, result.lower, tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "hello";
        string_stat result = get_stats(sentence);

        tr++;
        if (!assert_int_equal("lowercase only: length",
                              5, result.length, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("lowercase only: capitals",
                              0, result.caps, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("lowercase only: lowercase",
                              5, result.lower, tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "AaZz09!? ";
        string_stat result = get_stats(sentence);

        tr++;
        if (!assert_int_equal("mixed letters and symbols: length",
                              9, result.length, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("mixed letters and symbols: capitals",
                              2, result.caps, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("mixed letters and symbols: lowercase",
                              2, result.lower, tr)) {
            fc++;
        }
    }

    // Print Results 
    printf("\n===== TEST SUMMARY =====\n");
    printf("Total:  %d\n", tr);
    printf("Passed: %d\n", tr - fc);
    printf("Failed: %d\n", fc);
    return fc;
}