#include "main.h"
/**
 * execute_command - create a child process and the command
 * that gives an argument
 * @args: string
 *
 * Return: nothing
 */
void execute_command(char **args)
{
	int status;
	pid_t pid = fork();

	if (args[0] == NULL)
		return;

	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("command not found");
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
}
