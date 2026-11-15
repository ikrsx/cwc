#ifndef STACK_H

struct stack {
  char **strings;
  int top;
};

typedef struct stack stack;

stack init_stack_string(int size);
void push_stack(char *arg, stack *stack);
stack pop_stack(stack *stack);

#endif // STACK_H
