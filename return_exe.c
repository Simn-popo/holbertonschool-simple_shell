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
	int i = 0, j = 0;
	char *path[1024];
	char *full_path;
	char temp[1024];
	char *token;

	full_path = strdup(getenv("PATH"));

	token = strtok(full_path, ":");
	
	while (token != NULL)
        {
                path[i++] = token;
                token = strtok(NULL, ":");
        }

        path[i] = NULL;

	while (path[j] != NULL)
	{
		temp[0] = '\0';
		strcat(temp, path[j]);
		strcat(temp, "/");
		strcat(temp, args[0]);

		if (access(temp, F_OK) == 0)
		{
			args[0] = strdup(temp);
			free(full_path);
			return (0);
		}
		j++;
	}

	free(full_path);
	return (-1);
}
