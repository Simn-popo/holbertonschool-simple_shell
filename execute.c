#include "main.h"
/**
 * execute_command - create a child process and the command
 * that gives an argument
 * @args: ..
 * Return: nothing
 */
void execute_command(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		exit(1);
	}

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
}
