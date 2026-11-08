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
    char temp_str[MAX_LINE + 2];
    int endflag = 0;
    const char* deletetemplate = "DELETE";
    char** logs = create_logs();

    // I will make this non a piece of shit I SWEAR by the heavens
    /*
    so, we need to getchar, lines of MAX_LINE+2 (max length + \n and or EOF + '\0')

    when we get each line we need to check, in order

    is it DELETE?
    is it empty?
    if neither append
    print logs after each line

    need to stop at \n and know to stop looping after EOF

    then run free_logs
    
    */

    //main logic loop

        // null terminate end of string
        temp_str[MAX_LINE+1] = '\0';

        //read characters from redirect
        while(endflag != 1){

            for(int i = 0; i < MAX_LINE + 1; i++){
                int staging = getchar();
                if(staging == EOF){
                    printf("ending\n");
                    temp_str[i] = staging;
                    endflag = 1;
                    break;
                }
                else if(staging == '\n'){
                    temp_str[i] = staging;
                    break;
                }
                else{
                    temp_str[i] = staging;
                }
            }
            // done getting this line
            // logic from here is as follows
            // if index [0] == EOF or == '\n', it is an empty string, therefore do nothing and continue if '\n' or end if EOF
            if(temp_str[0] == EOF || temp_str[0] == '\n'){
                // can just continue even if EOF, because if empty EOF, then endflag will be set and while loop will break
                continue;
            }
            // check if it is delete
            char deleteTemplate[5] = "DELETE";
            int isDelete = 1;
            for(int i = 0; i < 6; i++){
                if(deleteTemplate[i] != temp_str[i]){
                    isDelete = 0;
                }
            }
            if(isDelete == 1){
                delete_last_log(logs, &count);
            } 
            // if empty continued, if delete then delete = 1
            // so if to appen can just check if we are not delete
            if(isDelete != 1){
                append_logs(logs, &count, &capacity, temp_str);
            }
        }
}



int main() {

    process();
    return 0;

}



/* 

   while(1){

        //read characters from redirect
        temp_str[MAX_LINE+1] = '\0';
        for(int i = 0; i < MAX_LINE + 1; i++){
            int staging = getchar();
            if(staging == EOF){
                printf("ending\n");
                endflag = 1;
                break;
            }
            temp_str[i] = staging;
            
            if(staging == '\n'){
                break;
            }
        }
        if(strcmp(temp_str,deletetemplate)==0 && temp_str[0] != '\n' && temp_str[0] != EOF){
            logs = append_logs(logs,&count,&capacity,temp_str);
        }
        else if(temp_str[0] == '\n'){
            if(endflag == 0){
                continue;
            }
        }
        else if(strcmp(temp_str,deletetemplate)){
            delete_last_log(logs,&count);
            
        }
        
        printf("%s",temp_str);

        if(endflag == 1){
            break;
        }
        
    }
    free_logs(logs,count);
    return;



    */