#include "main.h"
/**
 * 
 *
 * 
 *
 * 
 */

int return_exe(char **args)
{
	int i = 0;
	char *path[1024];
	char *full_path;
	char temp[1024];
	char *delim =":";

	full_path = strdup(getenv("PATH"));

	parse_command(full_path, path, delim);

	while (path[i] != NULL)
	{
		temp[0] = '\0';
		strcat(temp, path[i]);
		strcat(temp, "/");
		strcat(temp, args[0]);

		if (access(temp, F_OK) == 0)
		{
			args[0] = strdup(temp);
			free(full_path);
			return (0);
		}
		i++;
	}

	free(full_path);
	return (-1);
}
