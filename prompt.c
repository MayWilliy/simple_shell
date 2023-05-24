#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/types.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point
 * prompt - Display a prompt and wait for the user to type a command
 * Return: Nothing cause it is void
 */
int main(void)
{
	char *command = NULL;
	size_t command_length = MAX_COMMAND_LENGTH;

	while (true)
	{
	if (isatty(STDIN_FILENO)== 1){
			write(STDIN_FILENO, "shell >", 7);
	fflush(stdout);
	}
	if (getline(&command, &command_length, stdin) != -1)
	{
	command[strcspn(command, "\n")] = '\0';

	/*Fork a new process*/
	pid_t pid = fork();

	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	execlp(command, command, NULL);
	perror("exec");
	exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	}
	else
	{
	break;
	}
	}
	free(command);
	return (0);
}
