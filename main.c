#include "main.h"
/**
 * main - entry point UNIX command line interpreter
 * Return : always 0
 */

int main(void)
{
	char *command = NULL, *args[1024];
	size_t len = 0;
	ssize_t nread;
	int exit_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Hugo is the best SWE, i agree: ");

		nread = getline(&command, &len, stdin);
		if (nread == -1)
			break;

		command[strcspn(command, "\n")] = '\0';
		parse_command(command, args, " ");

		if (args[0] == NULL)
			continue;

		if (strcmp(args[0], "env") == 0)
			print_env(environ);
		else if (strchr(args[0], '/'))
			execute_command(args, environ);
		else if (return_exe(args, environ) > 0)
		{
			execute_command(args, environ);
			free(args[0]);
		}
		else
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	}
	free(command);
	return (exit_status);
}
