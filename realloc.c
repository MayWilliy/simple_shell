#include "shell.h"

/**
 * _memset - This fills the memory with a constant byte
 * @s: This denotes the pointer to the memory area
 * @b: This denotes the byte to fill *s with
 * @n: This denotes the amount of bytes to be filled
 * Return: should return (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - This frees a string of strings
 * @pp: A string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - This reallocates a block of memory
 * @ptr: A pointer to previous malloc'ated block
 * @old_size: The  byte size of previous block
 * @new_size: The byte size of new block
 *
 * Return: this should return a pointer to the  old block name
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
