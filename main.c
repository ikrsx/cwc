#include <stdio.h>
#include <stdlib.h>

#include "include/cmdopts.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Error: No valid option or filename supplied\n");
    return EXIT_FAILURE;
  }

  if (is_option(argv[1]) == 0) {
    printf("%s is a valid option\n", argv[1]);
    return EXIT_SUCCESS;
  }

  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: %s is not a valid option or filename\n", argv[1]);
    return EXIT_FAILURE;
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
