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

	strcpy(temp, "/");
	strcat(temp, args[0]);
	args[0] = temp;

	while (path[j] != NULL)
	{
		strcat(path[j], args[0]);

		if (access(path[j], F_OK) == 0)
		{
			args[0] = path[j];
			free(full_path);
			return (0);
		}
		j++;
	}

	free(full_path);
	return (-1);
}
