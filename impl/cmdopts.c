#include <stdio.h>

#include "../include/cmdopts.h"
#include "../include/cwc.h"

void default_option(FILE **fp, char filename[]) {
  int ccount = count_chars(fp);
  int wcount = count_words(fp);
  int lcount = count_lines(fp);

  printf("---- %s ----\n", filename);
  printf("Charecters: %d\n", ccount);
  printf("Words: %d\n", wcount);
  printf("Lines: %d\n", lcount);
  printf("Total Bytes: %d\n", ccount);
}
