#include "header.h"


/**
 * _puterror - Prints an error message to the standard error stream
 * @err: The error message to print
 *
 * Return: Void
 */
void _puterror(char *err)
{
	if ((_write_stderr(err)) == -1)
	{
		perror("write");
	}
}

/**
 *_putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Prints a string to the standard output stream
 * @str: The string to print
 *
 * Return: Void
 */
void _puts(char *str)
{
	if ((_write_stdout(str)) == -1)
	{
		perror("write");
	}
}

