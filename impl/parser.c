#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/operations.h"
#include "../include/parser.h"
#include "../include/stack.h"

int is_option(char *arg) {
  regex_t regex;
  int value = regcomp(&regex, "^--", REG_EXTENDED);

  if (value == 0) {
    value = regexec(&regex, arg, 0, NULL, 0);
    return value;
  }
  return EXIT_FAILURE;
}

void init_command(char *arg, FILE *fp) {
  if (strncmp(arg, "--version", sizeof("--version")) == 0 ||
      strncmp(arg, "-v", sizeof("-v")) == 0) {

    printf("cwc version: 0.0.1-alpha\n");

  } else if (strncmp(arg, "--characters", sizeof("--characters")) == 0 ||
             strncmp(arg, "-c", sizeof("-c")) == 0) {

    (fp == NULL) ? printf("Error: file does not seems to exists.\n")
                 : printf("Characters: %d\n", count_chars(&fp));

  } else if (strncmp(arg, "--words", sizeof("--words")) == 0 ||
             strncmp(arg, "-w", sizeof("-w")) == 0) {

    (fp == NULL) ? printf("Error: file does not seems to exists.\n")
                 : printf("Words: %d\n", count_words(&fp));

  } else if (strncmp(arg, "--lines", sizeof("--lines")) == 0 ||
             strncmp(arg, "-l", sizeof("-l")) == 0) {

    (fp == NULL) ? printf("Error: file does not seems to exists.\n")
                 : printf("Lines: %d\n", count_lines(&fp));

  } else if (strncmp(arg, "--bytes", sizeof("--bytes")) == 0 ||
             strncmp(arg, "-b", sizeof("-b")) == 0) {

    (fp == NULL) ? printf("Error: file does not seems to exists.\n")
                 : printf("Words: %d\n", count_words(&fp));

  } else {

    printf("Unknown option: %s\n", arg);
  }
}

int parse_command(int argc, char **argv) {
  if (argc == 1) {
    printf("Error: Required arguments not supplied.\n");
    return EXIT_FAILURE;
  }

  FILE *fp;
  int top = -1;
  char **command_stack = init_stack(argc);
  if (command_stack == NULL) {
    printf("Error: Unable to parse the commands.\n");
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    if (is_option(argv[i]) != 0) {
      fp = fopen(argv[i], "r");

      if (fp == NULL) {
        printf("Error: cannot open file\n");
        return EXIT_FAILURE;
      }
    } else {
      push_command(argv[i], &top, &command_stack);
    }
  }

  while (top != -1) {
    init_command(pop_command(&top, command_stack), fp);
  }

  free(command_stack);
  free(fp);

  return EXIT_SUCCESS;
}
