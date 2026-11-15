#include "stack.h"
#include <stdio.h>

#ifndef PARSER_H

struct command {
  stack command_stack;
  stack file_stack;
  int exit_code;
};

typedef struct command command;

command parse_command(int argc, char **argv);
void run_commands(command *cmd);

#endif // PARSER_H
