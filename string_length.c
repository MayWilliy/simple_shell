#include "shell.h"

/**
 * _strlen - This returns the length of a string
 * @s: The string whose length to check
 *
 * Return: returns an integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - This performs lexicogarphic comparison of two strangs.
 * @s1: This denotes first string
 * @s2: This denotes the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - This checks if needle starts with haystack
 * @haystack: The string to search
 * @needle: The substring to find
 *
 * Return: This returns the address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - This concatenates two strings
 * @dest: This describes  the destination buffer
 * @src: This describes the source buffer
 *
 * Return: returns a pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
