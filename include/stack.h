#ifndef STACK_H

char **init_stack(int size);
void push_command(char *arg, int *top, char **command_stack);
char *pop_command(int *top, char **command_stack);

#endif // STACK_H
