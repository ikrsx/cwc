#include <stdlib.h>

#include "include/cmdopts.h"

int main(int argc, char *argv[]) {
  if (parse_command(argc, argv))
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
