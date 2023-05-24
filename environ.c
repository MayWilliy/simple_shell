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

