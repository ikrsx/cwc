#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/cmdopts.h"
#include "../include/cwc.h"

static FILE *fp;

int is_option(char *arg) {
  regex_t regex;
  int value = regcomp(&regex, "^--", REG_EXTENDED);

  if (value == 0) {
    value = regexec(&regex, arg, 0, NULL, 0);
    return value;
  }
  return EXIT_FAILURE;
}

void select_command(char *arg) {
  if (strncmp(arg, "--version", sizeof("--version")) == 0 ||
      strncmp(arg, "-v", sizeof("-v")) == 0) {

    printf("cwc version: 0.0.1-alpha\n");

  } else if (strncmp(arg, "--characters", sizeof("--characters")) == 0 ||
             strncmp(arg, "-c", sizeof("-c")) == 0) {

    if (fp == NULL) {
      printf("Error: file does not seems to exists.\n");
    } else {
      printf("Characters: %d\n", count_chars(&fp));
    }

  } else if (strncmp(arg, "--words", sizeof("--words")) == 0 ||
             strncmp(arg, "-w", sizeof("-w")) == 0) {

    if (fp == NULL) {
      printf("Error: file does not seems to exists.\n");
    } else {
      printf("Words: %d\n", count_words(&fp));
    }

  } else if (strncmp(arg, "--lines", sizeof("--lines")) == 0 ||
             strncmp(arg, "-l", sizeof("-l")) == 0) {

    if (fp == NULL) {
      printf("Error: file does not seems to exists.\n");
    } else {
      printf("Lines: %d\n", count_lines(&fp));
    }

  } else if (strncmp(arg, "--bytes", sizeof("--bytes")) == 0 ||
             strncmp(arg, "-b", sizeof("-b")) == 0) {

    if (fp == NULL) {
      printf("Error: file does not seems to exists.\n");
    } else {
      printf("Words: %d\n", count_words(&fp));
    }

  } else {
    default_option(&fp);
  }
}

void default_option(FILE **fp) {
  int ccount = count_chars(fp);
  int wcount = count_words(fp);
  int lcount = count_lines(fp);

  printf("Characters: %d\n", ccount);
  printf("Words: %d\n", wcount);
  printf("Lines: %d\n", lcount);
  printf("Total Bytes: %d\n", ccount);
}

int parse_command(int argc, char **argv) {
  int i = 1;

  if (argc == 1) {
    printf("Error: Required arguments not supplied.\n");
    return EXIT_FAILURE;
  }

  while (i != argc) {
    select_command(argv[i]);
    i++;
  }

  return EXIT_SUCCESS;
}
