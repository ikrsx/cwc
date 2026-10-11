#include <stdlib.h>

#include "../include/stack.h"

char **init_stack(int size) {
  char **stack = malloc(size * sizeof(char *));

  if (stack == NULL)
    return NULL;

  return stack;
}

void push_command(char *arg, int *top, char ***command_stack) {
  (*top)++;
  *command_stack[*top] = arg;
}

char *pop_command(int *top, char **command_stack) {
  if (*top == -1)
    return "\0";

  char *rs = command_stack[*top];
  (*top)--;

  return rs;
}
