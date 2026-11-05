#ifndef PARSER_H
#define PARSER_H

#define CMD_GATHER (0)
#define CMD_USE (1)
#define CMD_FIND (2)
#define CMD_INVENTORY (3)
#define CMD_DISCARD (4)
#define CMD_CRAFT (5)
#define CMD_STATS (6)
#define CMD_QUIT (7)
#define CMD_AUTOCRAFT (8)
#define CMD_INVALID (9)

#define BUFFER_SIZE (256)

typedef struct Command {
    unsigned int cmd;
    char item[64];
    unsigned int quantity;
} Command;

extern int parse_command(const char* line, Command* out);

#endif 