#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/command.h"
#include "../include/operations.h"

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

    printf("Characters: %d\n", count_chars(&fp));

  } else if (strncmp(arg, "--words", sizeof("--words")) == 0 ||
             strncmp(arg, "-w", sizeof("-w")) == 0) {

    printf("Words: %d\n", count_words(&fp));

  } else if (strncmp(arg, "--lines", sizeof("--lines")) == 0 ||
             strncmp(arg, "-l", sizeof("-l")) == 0) {

    printf("Lines: %d\n", count_lines(&fp));

  } else if (strncmp(arg, "--bytes", sizeof("--bytes")) == 0 ||
             strncmp(arg, "-b", sizeof("-b")) == 0) {

    printf("Words: %d\n", count_words(&fp));

  } else if (strncmp(arg, "", sizeof("")) == 0) {

    printf("Characters: %d\n", count_chars(&fp));
    printf("Words: %d\n", count_words(&fp));
    printf("Lines: %d\n", count_lines(&fp));

  } else {

    printf("Unknown option: %s\n", arg);
  }
}

void run_commands(command cmd) {
  if (cmd.file_stack.top == 0) {
    for (int i = cmd.command_stack.top; i > 0; i--) {
      if (strncmp(cmd.command_stack.strings[i], "--version",
                  sizeof("--version")) == 0) {
        init_command("--version", NULL);
        break;
      }
    }
  } else if (cmd.command_stack.top > 0 && cmd.file_stack.top > 0) {
    for (int i = cmd.file_stack.top; i > 0; i--) {
      for (int j = cmd.command_stack.top; j > 0; j--) {
        FILE *fp = fopen(cmd.file_stack.strings[i], "r");

        if (fp == NULL) {
          fprintf(stderr, "Error: File %s does not exists.\n",
                  cmd.file_stack.strings[i]);
        } else {
          printf("\n------ %s ------\n", cmd.file_stack.strings[i]);
          init_command(cmd.command_stack.strings[j], fp);
          fclose(fp);
        }
      }
    }
  } else if (cmd.command_stack.top == 0) {
    for (int i = cmd.file_stack.top; i > 0; i--) {
      FILE *fp = fopen(cmd.file_stack.strings[i], "r");

      if (fp == NULL) {
        fprintf(stderr, "Error: File %s does not exists.\n",
                cmd.file_stack.strings[i]);
      } else {
        printf("\n------ %s ------\n", cmd.file_stack.strings[i]);
        init_command("", fp);
        fclose(fp);
      }
    }
  }
}

command parse_command(int argc, char **argv) {
  command cmd;

  cmd.command_stack = init_stack_string(argc);
  if (sizeof(cmd.command_stack) == 0) {
    fprintf(stderr, "Error: Unable to allocate command stack.\n");
    cmd.exit_code = EXIT_FAILURE;
    return cmd;
  }

  cmd.file_stack = init_stack_string(argc);
  if (sizeof(cmd.file_stack) == 0) {
    fprintf(stderr, "Error: Unable to allocate file stack.\n");
    cmd.exit_code = EXIT_FAILURE;
    return cmd;
  }

  for (int i = 1; i < argc; i++) {
    if (is_option(argv[i]) != 0) {
      push_stack(argv[i], &cmd.file_stack);
    } else {
      push_stack(argv[i], &cmd.command_stack);
    }
  }

  return cmd;
}
