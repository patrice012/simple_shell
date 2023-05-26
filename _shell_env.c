#include "header.h"

/**
 * _env - prints all environmental variables.
 */
void _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_str(environ[i]);
		print_str("\n");
	}
}
