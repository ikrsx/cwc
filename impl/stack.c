#include <stdlib.h>

#include "../include/stack.h"

stack init_stack_string(int size) {
  stack stack;
  stack.strings = malloc(size * sizeof(char *));
  return stack;
}

void push_stack(char *arg, stack *stack) {
  stack->top++;
  stack->strings[stack->top] = arg;
}

char *pop_stack(int *top, char **command_stack) {
  if (*top == -1)
    return "\0";

  char *rs = command_stack[*top];
  (*top)--;

  return rs;
}
