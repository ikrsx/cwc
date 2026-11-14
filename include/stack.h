#ifndef STACK_H

char **init_stack(int size);
void push_stack(char *arg, int *top, char **command_stack);
char *pop_stack(int *top, char **command_stack);

#endif // STACK_H
