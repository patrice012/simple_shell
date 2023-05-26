#include "main.h"

/**
 * _clear - clears the terminal screen.
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/
int _clear(void)
{
	print_str("\033[2J\033[H");
	return (1);
}
