#include <stdio.h>
#include <stdlib.h>

#include "include/command.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Error: Required arguments not supplied.\n");
    return EXIT_FAILURE;
  }

  command cmd = parse_command(argc, argv);

  if (cmd.exit_code == EXIT_FAILURE) {
    fprintf(stderr, "Error: Unable to parse command.\n");
    return cmd.exit_code;
  }

  return EXIT_SUCCESS;
}
