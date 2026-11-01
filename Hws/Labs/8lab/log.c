#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "log.h"

/*
This function uses calloc to create space for the array of pointers
The INITIAL_MAX constant is provided in log.h. Enough space to 
hold INITIAL_MAX char* should be allocated

@return pointer to the allocated array of char*
*/
char **create_logs() {

    char** log = calloc(INITIAL_MAX, sizeof(char*));
    return log;

}

/*
This function takes a pointer to a message, allocates space for it, 
copies the message into the allocated space, and then adds a pointer
to this allocated space to the logs array.

If there is not enough space for the message in the array, the array
should under go a call to realloc to double its capacity before 
adding the new message pointer. When performing this operation
the messsage "Capacity dobuled from %d to %d" should be printed
with correct numbers included.

The count and capacity are updated as needed.

@param **logs pointer to the array of char* pointing to messages
@param *count pointer to the current number of messages in the array
@param *capacity pointer to the current capacity of the log
@param *message a pointer to the next message to add to the array

@return the updated logs pointer
*/
char **append_logs(char **logs, int *count, int *capacity, char *message) {

    char** logcpy = logs;
    if( (*capacity - *count) <= 0){
        logs = realloc(logs, (sizeof(char*)*(*capacity*2)));
        // if logs is null we are so fucked
        printf("Capacity doubled from %d to %d\n", *capacity, (*capacity*2));
        *capacity = *capacity*2;
    }
    logs[*count] = message;
    *count = *count+1;

    return logs;

}

/*
This function deletes the the last filled element in the array.
If there is no entry to delete, "No entry to delete" is printed.
If an entry can be deleted, it must have its message freed.

The count is updated as needed.

@param **logs the pointer to the array of char* pointing to messages
@param *count the number of entries currently populated
*/
void delete_last_log(char **logs, int *count) {

    if(*count == 0){
        printf("No entry to delete\n");
        return;
    }
    else{
        free(logs[*count-1]);
        (*count)--;
        return;
    }

}

/*
This function frees all remaining messages and the logs array.

@param **logs the pointer to the array of char* pointing to messages
@param count the number of entries in the log array
*/
void free_logs(char** logs, int count) {

    for(int i = 0; i < count; i++ ){
        free(logs[i]);
    }
    free(logs);
    return;

}