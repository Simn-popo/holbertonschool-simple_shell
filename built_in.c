#include "main.h"

/**
 * print_env - display env variable
 * @env: Array of strings representing the environment variables
 *
 * Return: nothing
 */

void print_env(char **env, char **copy_env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		copy_env[i] = strdup(env[i]);
		i++;
	}
}

/**
 * free_env - Frees memory allocated for an array of strings
 * @env: The array of strings
 *
 * Return: nothing
 */

void free_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
}
/**
 * exit_shell - exit the mini shell
 * @ciao: The array of strings
 * @exit_status: The status code to exit with
 *
 * Return: nothing
 */

void exit_shell(char *ciao, int exit_status)
{
	if (ciao != NULL && strcmp(ciao, "exit") == 0)
	{
		free(ciao);
		exit(exit_status);
	}
}

/**
 * handle_env - Handles the "env" and "exit" built-in
 * @args: Array of input arguments
 * @env: Environment variables
 * @exit_status: Pointer
 * @copy_env: copy of environment variables
 *
 * Return: 1 if "env" was handled, 0 otherwise
 */

int handle_env(char **args, char **env, int *exit_status, char **copy_env)
{
	(void)copy_env;

	if (args[0] != NULL && strcmp(args[0], "env") == 0)
	{
		char *copy_env[1096];

		print_env(env, copy_env);
		*exit_status = 0;
		return (1);
	}
	if (args[0] != NULL && strcmp(args[0], "exit") == 0)
	{
		exit_shell(args[0], *exit_status);
	}
	return (0);
}
