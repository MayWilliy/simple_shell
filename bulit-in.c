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
