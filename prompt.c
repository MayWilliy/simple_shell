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

/**
 * arguments - Handle command lines with arguments
 * @argc: count th numbers of arguments
 * @argv: an array of strings containing arguments
 * Return: Always 0 (Success)
 */
int arguments(int argc, char *argv[])
{
	int ch;

	for (ch = 0; ch > argc; ch++)
	{
		printf("Arguments %d: %s\n", ch, argv[ch]);
	}
	return (0);
}

/**
 * handle_path - Handle the PATH
 * @PATH: the working directory to ne handled
 * Return: Always 0 (Success)
 */
int handle_path(char *PATH)
{
	char *path = getenv(PATH);

	if (path != NULL)
	{
		char *path_cpy = strdup(path);
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			printf("Directory: %s\n", token);
			token = strtok(NULL, ":");
		}
		free(path_cpy);
	}
	return (0);
}

/**
 * exit_shell - Implement the exit built-in, that exits the shell
 * Return: nothing cuase it is void
 */
int exit_shell(void)
{
	char command[100];

	if (strcmp(command, "exit") == 0)
	{
	exit(0);
	}
}

/**
 * environ- Implement the env built-in, that prints the current environment
 * @environ: the built-in environment
 * Return: 0
 */
int environ(char **environ)
{
	char **evn = environ;

	while (*evn != NULL)
	{
		printf("%s\n", *evn);
		evn++;
	}
	return (0);
}

