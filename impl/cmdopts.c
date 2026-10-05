#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/cmdopts.h"
#include "../include/cwc.h"

int is_option(char *arg) {
  regex_t regex;
  int value = regcomp(&regex, "^--", REG_EXTENDED);

  if (value == 0) {
    value = regexec(&regex, arg, 0, NULL, 0);
    return value;
  }
  return EXIT_FAILURE;
}

void default_option(FILE **fp, char *filename) {
  int ccount = count_chars(fp);
  int wcount = count_words(fp);
  int lcount = count_lines(fp);

  printf("---- %s ----\n", filename);
  printf("Charecters: %d\n", ccount);
  printf("Words: %d\n", wcount);
  printf("Lines: %d\n", lcount);
  printf("Total Bytes: %d\n", ccount);
}
