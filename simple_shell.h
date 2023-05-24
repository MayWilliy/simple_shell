#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

void shell_interactive(void);
void shell_no_interactive(void);
int main(void);
int arguments(int argc, char *argv[]);
int handle_path(char *PATH);
int exit_shell(void);
int environ(char **environ);

#endif

