#include "header.h"

/**
 * _env - Prints all the environment variables.
 *
 * Return: void.
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}
