/* The parser stays in the project. Only input collection uses getchar(). */
#include "parser.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    Command cmd;
    assert(parse_command("gather herb 12\n", &cmd) == 1);
    assert(cmd.cmd == CMD_GATHER && cmd.quantity == 12);
    assert(strcmp(cmd.item, "herb") == 0);

    assert(parse_command("use water 2", &cmd) == 1 && cmd.cmd == CMD_USE);
    assert(parse_command("find herb", &cmd) == 1 && cmd.cmd == CMD_FIND);
    assert(parse_command("discard herb", &cmd) == 1 && cmd.cmd == CMD_DISCARD);
    assert(parse_command("craft healing_potion", &cmd) == 1 && cmd.cmd == CMD_CRAFT);
    assert(parse_command("autocraft elixir", &cmd) == 1 && cmd.cmd == CMD_AUTOCRAFT);
    assert(parse_command("inventory", &cmd) == 1 && cmd.cmd == CMD_INVENTORY);
    assert(parse_command("stats", &cmd) == 1 && cmd.cmd == CMD_STATS);
    assert(parse_command("quit", &cmd) == 1 && cmd.cmd == CMD_QUIT);

    assert(parse_command("gather herb 0", &cmd) == 0);
    assert(parse_command("gather herb -1", &cmd) == 0);
    assert(parse_command("gather herb abc", &cmd) == 0);
    assert(parse_command("gather herb 2 extra", &cmd) == 0);
    assert(parse_command("find", &cmd) == 0);
    assert(parse_command("find Herb", &cmd) == 0);
    assert(parse_command("notacommand herb", &cmd) == 0);
    assert(parse_command("quit now", &cmd) == 0);
    assert(parse_command("   ", &cmd) == 0);
    assert(parse_command("gather herb 9999999999999999999", &cmd) == 0);

    assert(parse_command("gather herb 12abc", &cmd) == 0);
    assert(parse_command("gather herb -5", &cmd) == 0);
    assert(parse_command("gather herb 3.5", &cmd) == 0);
    assert(parse_command("gather herb 0", &cmd) == 0);
    assert(parse_command("gather herb 12", &cmd) == 1);
    puts("PASS: parser component");
    return 0;
}
