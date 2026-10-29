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

    return NULL;

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

    return NULL;

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

    return;

}

/*
This function frees all remaining messages and the logs array.

@param **logs the pointer to the array of char* pointing to messages
@param count the number of entries in the log array
*/
void free_logs(char** logs, int count) {

    return;

}