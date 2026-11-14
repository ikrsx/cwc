#include <stdio.h>

#ifndef PARSER_H

struct command {
  char **command_stack;
  char **file_stack;
  int exit_code;
};

typedef struct command command;

command parse_command(int argc, char **argv);

#endif // PARSER_H
