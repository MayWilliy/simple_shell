#include "pragma.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

extern char **environ;

/**
 * exec - execute cmd
 * @arrayv: vector
 * Return: 0
 */
int exec(int count, char *arrayv[])
{
	(void) count;

	char *in_exec_f = arrayv[0];
	const char *loc = "/bin/sh";
	char **environment_variables = NULL;
	int init_secondary;
	int wait_stat;
	char *comp_argv[3];
	
	comp_argv[0] = in_exec_f;
	comp_argv[1] = "-s";
	comp_argv[2] = NULL;

	init_secondary = fork();
	if (init_secondary == 0)
	{
		execve(loc, comp_argv, environment_variables);
		exit(EXIT_SUCCESS);
	}
	else if (init_secondary > 0)
	{
		wait(&wait_stat);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	return (0);
}

/**
 * main - Entry point
 * @argc: count args
 * @argv: args
 * Return: 0
 */
int mai(void)
{
	int wait_stat;
	char *command = { "ls", NULL};

	exec(1, &command);
	wait(&wait_stat);

	return (0);
}
                                
