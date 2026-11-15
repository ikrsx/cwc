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
