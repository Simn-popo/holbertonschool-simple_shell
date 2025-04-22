#include "main.h"

/**
 * _atoi - Custom implementation of atoi
 * @str: The string to convert to an int
 *
 * Return: The integer value
 */

int _atoi(const char *str)
{
	int i = 0, sign = 1, result = 0;

	/* Ignorer les espaces */
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	/* Vérifier le signe */
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	/* Convertir les chiffres */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}


/**
 * atoi - Manages internal commands: exit and env
 * @str: array of arguments (str[0] = "exit" or "env", etc.)
 *
 * Return: 1 if an internal command has been executed, 0 otherwise
 */

int exit(const char *str)
{
	int i;

	if (_atoi(str[0] == NULL))
		return (0);

	if (strcmp(str[0], "exit") == 0)
	{
		int code = 2;/*If the argument is supplied (ex:"exit 5") -->*/
		/*-->it is converted to an integer.*/
		if (args[1])
			code = atoi(args[1]);
		exit(code);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}
