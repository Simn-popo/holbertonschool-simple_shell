#include "main.h"
/**
 * parse_command - tokenized the string
 * @command: string
 * @args: array
 * @delim: Delimiter used for splitting the string
 *
 * Return: nothing
 */

void parse_command(char *command, char **args, char *delim)
{
	int i = 0;

	char *token = strtok(command, delim);

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, delim);
	}

	args[i] = NULL;
}
