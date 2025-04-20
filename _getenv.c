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
<<<<<<< HEAD
	int i, j, status;

	for (i = 0; env[i] != NULL; i++)
	{
		status = 1;

		for (j = 0; env[i][j] != '='; j++)
		{
			if (name[j] != env[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&env[i][j + 1]);
=======
	int i;
	size_t len = strlen(name);

	for (i = 0; env[i] != NULL; i++)
	{
		if(strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (&env[i][len + 1]);
>>>>>>> simon
		}
	}
	return (NULL);
}
