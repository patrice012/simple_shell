#include "header.h"

/**
 * _getline - reads an entire line from stream, 
 * storing the address of the buffer containing the text into *lineptr.
 * The buffer is null-terminated and includes the newline character,
 * if one was found
 * 
 * @lineptr: the buffer that the function should update each call
 * @n: the size of the line_buffer after update
 * @stream: the stream that the function should read the characters from
 * 
 * Return: On  success, return  the  number of characters read,
 * including the delimiter character, but not including the
 * terminating null byte ('\0'). This value can be used to
 * handle embedded null bytes in the line read.
 *
 * return -1 on failure to read a line (including end-of-file condition).
 * the buffer should be freed by the user program even on failure.
 */


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    getline(lineptr, n, stream);
}
