#include "main.h"
/**
 * handle_builtin - Manages internal commands: exit and env
 * @args: array of arguments (args[0] = "exit" or "env", etc.)
 *
 * Return: 1 if an internal command has been executed, 0 otherwise
 */
extern char **environ;
int handle_builtin(char **args)
{
	int i;

	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		int code = 0;
		if (args[1])
			code = atoi(args[1]);
		exit(code);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}
