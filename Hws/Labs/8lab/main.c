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
    // starter variables 2 electric boogaloo
    char** log = create_logs;
    const char* deletetemplate = "DELETE";
    int wedone = 0;
    // line always broken by \n or EOF as last
    // each line max MAX_LINE long

    //put line in
    while(1){
        for(int i = 0; i < (MAX_LINE+1); i++){
            char tempchar = getchar();
            if(tempchar == '\n' || tempchar == 'EOF'){
                temp_str[i] = '\0';
                if(tempchar == 'EOF'){
                    wedone = 1;
                }
                break;
            }
            else{
                temp_str[i] = getchar();
            }
        }
        //is it delete?
        for(int i = 0; i< (6); i++){
            if(deletetemplate[i] != temp_str[i]){
                break;
            }
            if(i == 5){
                delete_last_log(log, &count);
                temp_str[0] = '\0';
            }
        }
        //reset if we deleted
        if(temp_str[0] == '\0'){
            temp_str[0] == '0';
            continue;
        }
        // add it
        log = append_logs(log,&count,&capacity,temp_str);
        // check if last was EOF
        if(wedone == 1){
            free_logs(log,&count);
            return;
        }
        
    }
}

int main() {

    process();
    return 0;

}
