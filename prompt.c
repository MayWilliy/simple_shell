#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point
 * prompt - Display a prompt and wait for the user to type a command
 * Return: Nothing cause it is void
 */
int main(void)
{
	int argv[MAX_COMMAND_LENGTH];
	char command[MAX_COMMAND_LENGTH];
	char *path = getenv("PATH");
	char *arguments[MAX_COMMAND_LENGTH];

	while (true)
	{
	if (isatty(STDIN_FILENO))
		printf(STDOUT_FILENO, "shell >", 7);
	fflush(stdout);
	if (getline(command, MAX_COMMAND_LENGTH, stdin))
	{
		break;
	}
	command[strcspn(command, "\n")] = '\0';

	return (0);
}
