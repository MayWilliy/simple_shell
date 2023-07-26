#include "magicbox.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * main - The main entry point
 * @argc: The argument count
 * @argv: The argument vector
 * Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	char *path = "/bin/sh"; /*absolute path*/
	pid_t child;
	int status;
	char *myfile = argv[0];
	char **env_list = environ;
	char *commands[3];

	commands[0] = myfile;
	commands[1] = "-s";
	commands[2] = NULL;

	if (argc == 0)
	{
		exit(0);
	}
	child = fork();
	if (child == 0)
	{
		execve(path, commands, env_list);
	} else
	{
		wait(&status);
	}
	return (0);
}
