#include "main.h"
/**
 * _getenv - Retrieves the value of an environment
 * @name: the name of the environment variable to find
 * @env: the environment array
 *
 * Return: pointer to the value of the environment variable
 */
char *_getenv(const char *name, char **env)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (&env[i][len + 1]);
		}
	}
	return (NULL);
}
