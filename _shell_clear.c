#include "header.h"

/**
 * _clear - clears the terminal screen.
 * @args: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/
int _clear(char **args)
{
	(void)args; /* avoid "unsued parameter" warning */
	_puts("\033[2J\033[H");
	return (1);
}
