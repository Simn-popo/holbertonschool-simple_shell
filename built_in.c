#include "main.h"

/**
 * print_env - display env variable
 * @env: Array of strings representing the environment variables
 *
 * Return: nothing
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
