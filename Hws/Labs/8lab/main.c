#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "log.h"

/*
This function prints out the stored events

@param **logs pointer to the array of char* pointing to messages
@param count the number of entires in the log
*/
void print_logs(char **logs, int count)
{
    printf("Stored log events (%d):\n", count);
    for (int i = 0; i < count; i++)
        printf("[%d] %s\n", i + 1, logs[i]);
}

/*
This function reads in, using getchar(), input from a redirected file.
It starts by creating the pointer array with a call to create_logs
It then reads one line at a time and performs appropriate action.
1. if the line reads "DELETE", it calls delete_last_log
2. if the message is empty, it does nothing
3. otherwise, it calls append_logs to add the entry
After processing each line, it calls print_logs
After printing, it calls free_logs to free up the remaining allocated memory
*/
void process() {
    // Starter Variables to help you begin
    int count = 0;
    int capacity = INITIAL_MAX;
    char temp_str[MAX_LINE + 1];
    


    return;
}

int main() {

    process();
    return 0;

}
