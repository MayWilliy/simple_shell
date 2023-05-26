<<<<<<< HEAD
#include "shell.h"
=======
#include <shell.h>
>>>>>>> c77d923d507896820c433aff94cf2c5a7b8f79a6

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
