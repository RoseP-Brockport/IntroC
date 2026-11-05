#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

/*
This function takes a string representing a command and identifies the
corresponding command type. If the provided string does not match any
supported command, CMD_INVALID is returned.

@param word string representation of the command
@return the command type corresponding to the provided string,
        or CMD_INVALID if the command is not recognized
*/
static int lookup_command_type(const char *word) {
    if (strcmp(word, "gather") == 0) return CMD_GATHER;
    if (strcmp(word, "use") == 0) return CMD_USE;
    if (strcmp(word, "find") == 0) return CMD_FIND;
    if (strcmp(word, "inventory") == 0) return CMD_INVENTORY;
    if (strcmp(word, "discard") == 0) return CMD_DISCARD;
    if (strcmp(word, "craft") == 0) return CMD_CRAFT;
    if (strcmp(word, "stats") == 0) return CMD_STATS;
    if (strcmp(word, "quit") == 0) return CMD_QUIT;
    if (strcmp(word, "autocraft") == 0) return CMD_AUTOCRAFT;
    return CMD_INVALID;
}

/*
This function determines whether a provided string represents a valid
item name. Valid item names must contain at least one character, consist
only of lowercase letters and underscores, and be fewer than 64
characters in length.

@param name string representation of the item name to validate
@return 1 if the item name is valid, 0 otherwise
*/
static int valid_item_name(const char *name) {
    if (name == NULL || *name == '\0') {
        return 0;
    }
    int length = 0;
    for (const char* p = name; *p != '\0'; ++p) {
        if (!(*p >= 'a' && *p <= 'z') && *p != '_') {
            return 0;
        }
        if (++length >= 64) {
            return 0;  
        } 
    }
    return 1;
}

/*
This function takes a line of input containing a player command and
attempts to interpret it as one of the supported inventory commands.

The input is separated into individual words, and the command type,
number of arguments, item name, and quantity are checked for validity.

If the command is valid, the provided Command structure is populated
with the command type and any required arguments.

Commands that are not recognized, contain an incorrect number of
arguments, or contain invalid item names or quantities are rejected.

@param line string containing the complete command to be interpreted
@param out pointer to the Command structure that will store the
           interpreted command and its arguments
@return 1 if the command was successfully interpreted, 0 otherwise
*/
int parse_command(const char* line, Command* out) {
    if (line == NULL || out == NULL || strlen(line) >= BUFFER_SIZE) {
        return 0;
    }

    out->cmd = CMD_INVALID;
    out->item[0] = '\0';
    out->quantity = 0;

    char buffer[BUFFER_SIZE + 1];
    char* words[4] = {NULL, NULL, NULL, NULL};
    char* buff = buffer;
    // const char* mover = line;
    char* starts = buff; 
    int count = 0;
    while(count < 4) {
        while(*line != ' ' && *line != '\0' && *line != '\n') {
            *buff = *line;
            buff++;
            line++;
        }
        *buff = '\0';
        buff++;

        words[count] = starts;
        starts = buff;
        count++;
        if (*line == '\0' || *line == '\n') {
            break;
        }
        line++;
    }
    if (*line != '\0' && *line != '\n') {
        out->cmd = CMD_INVALID;
        return 0;
    }   
    if(count == 4 && strcmp("", words[3]) == 0) {
        count--;
    }
    if (count == 0 || count == 4 ) {
        return 0;
    }

    out->cmd = lookup_command_type(words[0]);
    if(out->cmd == CMD_INVALID) {
        return 0;
    }
    if (count == 1 && (out->cmd == CMD_INVENTORY || out->cmd == CMD_STATS || out->cmd == CMD_QUIT)) {
        return 1;
    }
    
    if (count == 3 && valid_item_name(words[1]) && (out->cmd == CMD_GATHER || out->cmd == CMD_USE)) {
        for (const char* p = words[2]; *p != '\0'; p++) {
            if (*p < '0' || *p > '9') {
                out->cmd = CMD_INVALID;
                return 0;
            }
        }
        int amount = atoi(words[2]);
        if (amount <= 0) {
            out->cmd = CMD_INVALID;
            return 0;
        }    
        strcpy(out->item,words[1]);
        out->quantity = amount;
        return 1;
    }
    if (count == 2 && valid_item_name(words[1]) && (out->cmd == CMD_FIND || out->cmd == CMD_DISCARD || out->cmd == CMD_CRAFT || out->cmd == CMD_AUTOCRAFT)) {
        strcpy(out->item, words[1]);
        return 1;
    }
    out->cmd = CMD_INVALID;
    return 0;

}