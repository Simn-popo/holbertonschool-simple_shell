#include "main.h"
/**
 * return_exe - Search for a command in the PATH
 * @args: Array of arguments, where args[0] is the name of the command
 * @env: ...
 *
 * Return: 0 if the executable is found, -1 otherwise
 */
int return_exe(char **args, char **env)
{
	int i = 0;
	char *path_list[1024];
	char *path_env, *dup_path;
	char temp[1024];
	char *delim = ":";

	path_env = _getenv("PATH", env);
	if (path_env == NULL || *path_env == '\0')
		return (-1);
	dup_path = strdup(path_env);
	if (dup_path == NULL)
		return (-1);

	parse_command(dup_path, path_list, delim);
	while (path_list[i] != NULL)
	{
		strcpy(temp, path_list[i]);
		strcat(temp, "/");
		strcat(temp, args[0]);

		if (access(temp, F_OK) == 0)
		{
			if (args[0 != NULL])
			free(args[0]);
			args[0] = strdup(temp);
			if (args[0] == NULL)
			{
				free(dup_path);
				return (-1);
			}
			free(dup_path);
			return (0);
		}
		i++;
	}
	free(dup_path);
	return (-1);
}
