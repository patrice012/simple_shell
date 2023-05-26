#include "main.h"

/**
 * _write - write string to file descriptor
 * @str: string to print
 * @fd: file descriptor
 * Return: Number of bytes written
 */

int _write(char *str, int fd)
{
	int len = 0;

	len = _strlen(str);
	return (write(fd, str, len));
}

/**
 * _write_stdout - print string to stdout
 * @str: string to write
 * Return: None
 */

int _write_stdout(char *str)
{
	return (_write(str, STDOUT_FILENO));
}


/**
 * _write_stderr - print string to stderror
 * @str: error message to write
 * Return: None
 */

int _write_stderr(char *str)
{
	return (_write(str, STDERR_FILENO));
}
