#include <stdio.h>
#include <stdlib.h>

#include "include/mywc.h"

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: Failed to read the file\n");
    printf("Exiting...\n");
    return EXIT_FAILURE;
  }

  int ccount = count_chars(&fp);
  int wcount = count_words(&fp);
  int lcount = count_lines(&fp);

  printf("---- %s ----\n", argv[1]);
  printf("Charecters: %d\n", ccount);
  printf("Words: %d\n", wcount);
  printf("Lines: %d\n", lcount);

  fclose(fp);

  return EXIT_SUCCESS;
}
