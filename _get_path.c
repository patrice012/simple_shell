#include "header.h"

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */
char *get_path(void)
{
	return (_get_env("PATH"));
}
