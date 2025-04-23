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

	if (env == NULL)
	{
		printf("error : env is null\n");
		return;
	}
	
	printf("DEBUG: Printing environment variables...\n");

	while (env[i] != NULL)
	{
		printf("env[%d] = %s\n", i, env[i]);
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * exit_shell - exit the mini shell
 * 
 */

void exit_shell (char *ciao, int exit_status)
{
	if (ciao != NULL && strcmp(ciao, "exit") == 0)
	{
		free(ciao);
		exit(exit_status);
	}
}

int handle_env(char **args, char **env, int *exit_status)
{
	if (args[0] != NULL && strcmp(args[0], "env") == 0)
	{
		printf("DEBUG: env command detected\n");
		print_env(env);
		*exit_status = 0;
		return(1);
	}
	if (args[0] != NULL && strcmp(args[0], "exit") == 0)
	{
		exit_shell(args[0], *exit_status);
	}
	return(0);
}
