/* Simple full-program checker: reads two text files.
   Usage: ./tests/check_output actual.out expected.checks

   Each line in the .checks file is text that must appear in the output.
   A line starting with ! must NOT appear.
   # starts a comment. No threads, fork(), exec(), pipes, or shell scripts.
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        puts("Usage: check_output actual.out expected.checks");
        return 1;
    }

    FILE *actual = fopen(argv[1], "r");
    FILE *checks = fopen(argv[2], "r");
    if (actual == NULL || checks == NULL) {
        puts("Could not open a test file.");
        if (actual != NULL) fclose(actual);
        if (checks != NULL) fclose(checks);
        return 1;
    }

    /* Every supplied program case produces fewer than 64 KB of output. */
    char output[65536];
    size_t length = fread(output, 1, sizeof(output) - 1, actual);
    output[length] = '\0';
    int too_long = fgetc(actual) != EOF;
    fclose(actual);

    if (too_long) {
        puts("FAIL: program output was too long to check.");
        fclose(checks);
        return 1;
    }

    int failed = 0;
    char line[256];
    while (fgets(line, sizeof(line), checks) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == '#' || line[0] == '\0') continue;
        if (line[0] == '!') {
            if (strstr(output, line + 1) != NULL) {
                printf("FAIL: unexpected text: %s\n", line + 1);
                failed = 1;
            }
        } else if (strstr(output, line) == NULL) {
            printf("FAIL: missing text: %s\n", line);
            failed = 1;
        }
    }
    fclose(checks);

    if (failed) {
        printf("See the actual output in %s\n", argv[1]);
        return 1;
    }
    printf("PASS: %s\n", argv[1]);
    return 0;
}
