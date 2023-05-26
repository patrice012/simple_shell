#include "main.h"

/**
 * get_input - Read the line of line_buffer from user.
 * @fd: file descriptor
 * @line_buffer: double pointer to hold user input
 * Return: Pointer to a buffer conatining the user's line_buffer.
*/
ssize_t get_input(char **line_buffer, int fd)
{
	size_t line_size = 0;
	ssize_t reads;

	/* get a line of line_buffer from user */
	/*reads = getline(&line_buffer, &line_size, stdin);*/
	reads  = _getline(line_buffer, &line_size, fd);
	return (reads);
}
