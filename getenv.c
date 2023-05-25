#include <shell.h>

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
			write("Directory: %s\n", token);
			token = strtok(NULL, ":");
		}
		free(path_cpy);
	}
}
