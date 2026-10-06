#include <stdio.h>

#ifndef CMDOPTS_H

int parse_command(int argc, char **argv);
void default_option(FILE **fp);
int is_option(char *arg);

#endif // CMDOPTS_H
