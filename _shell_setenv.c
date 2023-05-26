#include "header.h"

/**
 * _setenv - Set the value of an environment variable
 * @name: Argument name
 * @value: argument value
 *
 * Return: Nothing
 */
int _setenv(char *name, char *value)
{
	if (name == NULL || value == NULL || name[0] == '\0'
		|| _strchr(name, '=') != NULL)
	{
		print_err("Error: Invalid Arguments!\n");
		return (-1);
	}
	if (setenv(name, value, 1) != 0)
	{
		print_err("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @name: variable name
 *
 * Return: Nothing
 */
int _unsetenv(char *name)
{
	if (name == NULL)
	{
		print_err("Error: Invalid Arguments!\n");
		return (-1);
	}
	if (unsetenv(name) != 0)
		print_err("unsetenv");
	return (0);
}
