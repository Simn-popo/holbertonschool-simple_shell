#include "main.h"

/**
 * _atoi - Custom atoi to convert string to int
 * @str: The string to convert
 * Return: Converted integer
 */
int _atoi(const char *str)
{
	int i = 0, sign = 1, result = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}
