#include "main.h"
/**
 * main - Entry point UNIX command line interpreter
 *
 * Return: Always 0
 */

int main(void)
{
	char *command = NULL, *args[1024], *delim = " ";
	size_t len = 0;
	ssize_t nread;
	int exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Hugo is the best SWE, i agree: ");

		nread = getline(&command, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		parse_command(command, args, delim);
		if (args[0] == NULL)
			continue;

		if (strchr(args[0], '/'))
			execute_command(args);
		else if (return_exe(args) == 0)
		{
			execute_command(args);
			free(args[0]);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit_status = 127;
		}
	}
	free(command);
	return (exit_status);
}
