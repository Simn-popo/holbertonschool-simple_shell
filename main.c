#include "main.h"
/**
 * main - entry point UNIX command line interpreter
 * @ac: Argument count
 * @env: Array of environment variables
 *
 * Return: The exit status of the last executed command
 */

int main(int ac, char **env)
{
	char *ciao = NULL, *args[1024];
	size_t len = 0;
	ssize_t nread;
	int exit_status = 0;

	(void)ac;
	(void)env;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Hugo and Fabien is the best SWE, I agree: ");
		nread = getline(&ciao, &len, stdin);
		if (nread == -1)
			break;

		ciao[strcspn(ciao, "\n")] = '\0';
		exit_shell(ciao);
		parse_command(ciao, args, " ");

		if (args[0] == NULL)
			continue;

		if (strchr(args[0], '/') != NULL)
		{
			execute_command(args, environ);
		}
		else if (return_exe(args, environ) == 0)
		{
			execute_command(args, environ);
			free(args[0]);
		}
		else
		{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit_status = 127;
		}
	}
	free(ciao);
	return (exit_status);
}
