#include "main.h"

/**
 * print_env - display env variable
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
