#include "main.h"
/**
 * execute_command - create a child process and the command
 * that gives an argument
 * @args: string
 * @env: Array of strings
 *
 * Return: nothing
 */
int execute_command(char **args, char **env)
{
	int status;
	pid_t pid = fork();

	if (args[0] == NULL)
		return (0);

	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else
			return (-1);
	}
	return (-1);
}
