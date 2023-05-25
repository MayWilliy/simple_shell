#include "shell.h"

/**
 * get_environ - This will return the string array copy of our environmental
 * variable
 * @info: The structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return Value:It should always returns 0 meaning it ran successfully
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		 info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - This will remove or unset an environment variable
 * @info: The structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return value: This will return 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - This Initializes a new environment variable,
 *           or modify an existing one
 * @info: The structure containing potential arguments. It is used to maintain
 *        constant function prototype.
 * @var: The string environmental variable  property
 * @value: The string environmental variable value
 *  Return Value: This should always return 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	/*built in functions*/
	_strncpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
