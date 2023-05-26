#include "shell.h"

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
