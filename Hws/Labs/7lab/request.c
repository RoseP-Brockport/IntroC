#include <stdio.h>
#include <stdlib.h>

#include "request.h"
#include "processor.h"

void print_results(char *fields[], char *results[], int c) {
    for (int i = 0; i < c; i++)
    {
        if (results[i] == NULL)
            printf("%s: [NOT FOUND]\n", fields[i]);
        else
            printf("%s: [%s]\n", fields[i], results[i]);
    }
    printf("\n");
}

int make_requests() {
    
    // Test Case 1
    char data1[] = "session_status=EXPIRED;previous_user_id=1042;device_id=PC-482;status=ACTIVE;user_id=5831;session_id=AB9201;";

    char *fields1[] = {
        "user_id", "device_id", "session_id", "status"
    };

    char *results1[4] = {NULL};

    printf("Test Case 1\n");
    process(data1, fields1, results1, 4);
    print_results(fields1, results1, 4);


    // Test Case 2
    char data2[] = "user_agent=Firefox;session_id=Q7;status=FAILED;username=bob;user_id=220;device_id=PC-900;";

    char *fields2[] = {
        "status", "user_id", "device_id"
    };

    char *results2[3] = {NULL};

    printf("Test Case 2\n");
    process(data2, fields2, results2, 3);
    print_results(fields2, results2, 3);


    // Test Case 3
    char data3[] = "device_id=KALI-2;user_id=;previous_status=WAITING;session_id=AX9";

    char *fields3[] = {
        "user_id", "session_id", "status", "device_id"
    };

    char *results3[4] = {NULL};

    printf("Test Case 3\n");
    process(data3, fields3, results3, 4);
    print_results(fields3, results3, 4);

    // Test Case 4: Missing field with a similar name present
    char data4[] = "previous_session_id=OLD123;user_id=7210;device_id=PC-012;status=ACTIVE;";

    char *fields4[] = {
        "user_id", "session_id", "device_id", "status"
    };

    char *results4[4] = {NULL};

    printf("Test Case 4\n");
    process(data4, fields4, results4, 4);
    print_results(fields4, results4, 4);

    // Test Case 5: Every field is requested
    char data5[] = "session_status=EXPIRED;device_id=LAB-17;user_agent=Firefox;user_id=5841;session_id=TX-903;status=ACTIVE;";

    char *fields5[] = {
        "status", "user_id", "session_status",
        "session_id", "user_agent", "device_id"
    };

    char *results5[6] = {NULL};

    printf("Test Case 5\n");
    process(data5, fields5, results5, 6);
    print_results(fields5, results5, 6);

    return 0;
}