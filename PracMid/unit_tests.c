#include <stdlib.h>
#include <stdio.h>

#include "unit_tests.h"
#include "practice1.h"

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
        int first = 5;
        int second = 7;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("positive: return", 1, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("positive: first reset", 0, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("positive: second updated", 12, second, tr)) {
            fc++;
        }
    }
    {
        int first = 8;
        int second = -3;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("positive with negative second: return",
                                1, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("positive with negative second: first",
                                0, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("positive with negative second: second",
                                5, second, tr)) {
            fc++;
        }
    }
    {
        int first = 0;
        int second = 9;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("zero: return", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("zero: first unchanged", 0, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("zero: second unchanged", 9, second, tr)) {
            fc++;
        }
    }
    {
        int first = -4;
        int second = 2;
        int result = fix_bad_code(&first, &second);

        tr++;
        if (!assert_int_equal("negative: return", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("negative: first unchanged", -4, first, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("negative: second unchanged", 2, second, tr)) {
            fc++;
        }
    }

    printf("\n===== count_pairs =====\n");
    {
        char sentence[] = "";
        tr++;
        if (!assert_int_equal("empty string", 0,
                                count_pairs(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "abcd";
        tr++;
        if (!assert_int_equal("no adjacent matches", 0,
                                count_pairs(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "aabbccc";
        tr++;
        if (!assert_int_equal("overlapping and separate pairs", 4,
                                count_pairs(sentence), tr)) {
            fc++;
        }

    }
    {
        char sentence[] = "a  a";
        tr++;
        if (!assert_int_equal("spaces are not letter pairs", 0,
                                count_pairs(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "baaab";
        tr++;
        if (!assert_int_equal("overlapping pair", 2,
                                count_pairs(sentence), tr)) {
            fc++;
        }
    }
        {
        char sentence[] = "abba";
        tr++;
        if (!assert_int_equal("single pair", 1,
                                count_pairs(sentence), tr)) {
            fc++;
        }
    }

    printf("\n===== swap_case =====\n");
    {
        char sentence[] = "";
        int result = swap_case(sentence);
        tr++;
        if (!assert_int_equal("empty: count", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("empty: output", "", sentence,
                         sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "aAzZ";
        int result = swap_case(sentence);
        tr++;
        if (!assert_int_equal("case boundaries: count", 4, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("case boundaries: output", "AaZz", sentence,
                         sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = "Hello World 123!";
        int result = swap_case(sentence);
        tr++;
        if (!assert_int_equal("mixed text: count", 10, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("mixed text: output", "hELLO wORLD 123!",
                         sentence, sizeof(sentence), tr)) {
            fc++;
        }
    }
    {
        char sentence[] = " 123-!?";
        int result = swap_case(sentence);
        tr++;
        if (!assert_int_equal("nonletters: count", 0, result, tr)) {
            fc++;
        }
        tr++;
        if (!str_equal("nonletters: unchanged", " 123-!?", sentence,
                         sizeof(sentence), tr)) {
            fc++;
        }
    }

    printf("\n===== last_occurence =====\n");
    char last_empty[] = "";
    char last_abc[] = "abc";
    char last_banana[] = "banana";
    char last_absent[] = "abc";
    char last_spaces[] = "a a a";
    char capitals[] = "AbcAa";
    char lower_mixed[] = "CandleA";
    tr++;
    if (!assert_int_equal("empty string", -1,
                            last_occurence(last_empty, 'a'), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("first index", 0,
                            last_occurence(last_abc, 'a'), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("last repeated match", 5,
                            last_occurence(last_banana, 'a'), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("absent target", -1,
                            last_occurence(last_absent, 'x'), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("space target", 3,
                            last_occurence(last_spaces, ' '), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("capital target", 3,
                            last_occurence(capitals, 'A'), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("mixed case target", 1,
                            last_occurence(lower_mixed, 'a'), tr)) {
            fc++;
        }

    printf("\n===== find_next_capital =====\n");
    char capital_empty[] = "";
    char capital_first[] = "Abc";
    char capital_search[] = "abc D eF";
    char capital_skip[] = "abc D eF";
    char capital_none[] = "Abc";
    char capital_end[] = "abc D eF";
    char capitals_boundary[] = "weLcome Z to class";
    tr++;
    if (!assert_int_equal("empty string", -1,
                            find_next_capital(capital_empty, 0), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("capital at start", 0,
                            find_next_capital(capital_first, 0), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("skip lowercase and space", 4,
                            find_next_capital(capital_search, 0), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("skip earlier capital", 7,
                            find_next_capital(capital_skip, 5), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("no capitals remaining", -1,
                            find_next_capital(capital_none, 1), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("start at terminator", -1,
                            find_next_capital(capital_end, 8), tr)) {
            fc++;
        }
    tr++;
    if (!assert_int_equal("Z Case", 8,
                            find_next_capital(capitals_boundary, 5), tr)) {
            fc++;
        }

    printf("\n===== classify_digits =====\n");
    {
        int values[MAX_ARRAY] = {-14, -13, -8, -7, -6,
                                 -1, 0, 1, 7, 14};
        numerics result = classify_digits(values);

        tr++;
        if (!assert_int_equal("mixed: even count", 5,
                                result.num_evens, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("mixed: odd count", 5,
                                result.num_odds, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("mixed: multiples of 7", 5,
                                result.num_sevens, tr)) {
            fc++;
        }
    }
    {
        int values[MAX_ARRAY] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
        numerics result = classify_digits(values);

        tr++;
        if (!assert_int_equal("all odd: even count", 0,
                                result.num_evens, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all odd: odd count", 10,
                                result.num_odds, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all odd: multiples of 7", 0,
                                result.num_sevens, tr)) {
            fc++;
        }
    }
    {
        int values[MAX_ARRAY] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        numerics result = classify_digits(values);

        tr++;
        if (!assert_int_equal("all even: even count", 10,
                                result.num_evens, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all even: odd count", 0,
                                result.num_odds, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all even: multiples of 7", 1,
                                result.num_sevens, tr)) {
            fc++;
        }
    }
    {
        int values[MAX_ARRAY] = {7, 14, 21, 28, 35, 42, 49, 56, 63, 70};
        numerics result = classify_digits(values);

        tr++;
        if (!assert_int_equal("all multiples: even count", 5,
                                result.num_evens, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all multiples: odd count", 5,
                                result.num_odds, tr)) {
            fc++;
        }
        tr++;
        if (!assert_int_equal("all multiples: multiples of 7", 10,
                                result.num_sevens, tr)) {
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