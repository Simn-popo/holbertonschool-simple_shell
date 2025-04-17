#include "main.h"
/**
 * parse_command - tokenized the string
 * @command: ..
 * @args: ..
 *
 * Return: nothing
 */

void parse_command(char *command, char **args)
{
	int i = 0;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}
