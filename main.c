#include <stdio.h>
#include <stdlib.h>

#include "include/mywc.h"

int main(int argc, char *argv[]) {
  FILE *fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("Error: Failed to read the file\n");
    printf("Exiting...\n");
    fclose(fp);
    return EXIT_FAILURE;
  }

  int ccount = count_chars(&fp);
  int wcount = count_words(&fp);

  printf("---- %s ----\n", argv[1]);
  printf("Total charecters: %d\n", ccount);
  printf("Total words: %d\n", wcount);

  fclose(fp);

  return EXIT_SUCCESS;
}
