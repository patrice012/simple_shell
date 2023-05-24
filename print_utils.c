#include "header.h"

/**
 * _print - write string to file descriptor
 * @str: string to print
 * @fd: file descriptor
 * Return: None
 */

void _print(char *str, int fd)
{
	int len = 0;

	len = _strlen(str);
	write(fd, str, len);
}

/**
 * print_str - print string to stdout
 * @str: string to write
 * Return: None
 */

void print_str(char *str)
{
	_print(str, STDOUT_FILENO);
}


/**
 * print_error - print string to stderror
 * @str: error message to write
 * Return: None
 */

void print_error(char *str)
{
	_print(str, STDERR_FILENO);
}
