#include "main.h"

static char *last_input;
/**
 * get_input - Read the line of line_buffer from user.
 * @fd: file descriptor
 * Return: Pointer to a buffer conatining the user's line_buffer.
*/
char *get_input(int fd)
{
	char *line_buffer = NULL;
	size_t line_size = 0;
	ssize_t reads;


	/* get a line of line_buffer from user */
	/*reads = getline(&line_buffer, &line_size, stdin);*/
	reads  = _getline(&line_buffer, &line_size, fd);
	/* check for EOF or error */
	if (reads == -1)
	{
		free(line_buffer);
		print_str("\n");
		return (NULL);
	}
	/* remove trailing newline character */
	/*line_buffer[reads - 1] = '\0';*/

	/* update last_input to point to the new line_buffer */
	last_input = line_buffer;
	return (line_buffer);
}

/**
 * free_last_input - Frees the most recent line_buffer entered by the user.
 *
 * This function frees the memory allocated
 * for the most recent line_buffer string
 * entered by the user. It should be called
 * after the line_buffer string is no longer
 * needed.
 */
void free_last_input(void)
{
	free(last_input);
	last_input = NULL;
}
