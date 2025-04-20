#include "main.h"
/**
 * return_exe - Search for a command in the PATH
 * @args: Array of arguments, where args[0] is the name of the command
 *
 * Return: 0 if the executable is found, -1 otherwise
 */

int return_exe(char **args)
{
	int i = 0;
	char *path[1024];
	char *full_path;
	char temp[1024];
	char *delim = ":";

	full_path = _getenv("PATH", environ);
	if (full_path == NULL || *full_path == '\0')
		return (-1);

	full_path = strdup(full_path);
	if (full_path == NULL)
	{
		perror("error duplicating Path");
		return (-1);
	}

	parse_command(full_path, path, delim);

	while (path[i] != NULL)
	{
		temp[0] = '\0';
		strcat(temp, path[i]);
		strcat(temp, "/");
		strcat(temp, args[0]);

		if (access(temp, F_OK) == 0)
		{
			free(args[0]);
			args[0] = strdup(temp);
			free(full_path);
			return (0);
		}
		i++;
	}

	free(full_path);
	return (-1);
}
