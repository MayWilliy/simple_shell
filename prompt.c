#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point
 * prompt - Display a prompt and wait for the user to type a command
 * Return: Nothing cause it is void
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	/*char *path = getenv("PATH");*/
	/*char *arguments[MAX_COMMAND_LENGTH];*/

	while (true)
	{
	if (isatty(STDIN_FILENO))
		printf("shell >");
	fflush(stdout);
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		break;
	}
	command[strcspn(command, "\n")] = '\0';
	}

	return (0);
}
