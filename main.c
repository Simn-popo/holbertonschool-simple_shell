#include "main.h"
/**
 * main - Entry point UNIX command line interpreter
 *
 * Return: Always 0
 */

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	char *args[1024];
	ssize_t nread;
	char *delim = " ";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Hugo is the best SWE: ");

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

		if (strchr(args[0], '/') != NULL)
			execute_command(args);

		else if (return_exe(args) == 0)
		{
			execute_command(args);
			free(args[0]);
		}
	}
	free(command);
	return (0);
}
