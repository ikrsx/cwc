#include <stdio.h>
#include <stdlib.h>

#include "include/cmdopts.h"

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: Failed to read the file\n");
    printf("Exiting...\n");
    return EXIT_FAILURE;
  }

  default_option(&fp, argv[1]);

  fclose(fp);

  return EXIT_SUCCESS;
}
