#include "main.h"
/**
 * main - Entry point
 * Description: UNIX command line interpreter
 * @void: ..
 * Return: nothing
 */

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	char *args[1024];
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		nread = getline(&command, &len, stdin);

		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(command);
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		parse_command(command, args);

		execute_command(args);
	}
	free(command);
	return (0);
}
