#include "header.h"

/**
 * print_str - prints a string to stdout
 *
 * @s: pointer to an array of chars
 */
void print_str(char *s)
{
	_write_stdout(s);
}

/**
 * print_err - prints error to stderr
 *
 * @s: error message to print.
 */
void print_err(char *s)
{
	_write_stderr(s);
}

/**
 * _putchar - write a characeter to stdout
 * @c: character to write
 * Return: 1 for success and -1 for failure
 */

int _putchar(char c)
{
	return (write(1, &c, sizeof(c)));
}
