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

/*
 * ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
 * {
 *     getline(lineptr, n, stream);
 * }
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[BUFFER_SIZE];
    int buffer_position = 0;
    ssize_t line_position = 0;
    ssize_t r = 0, index = 0;
    /* Variable to keep track of characters read */
    ssize_t char_count = 0;
    /* allow to breack the two loop at the same moment */
    int should_break = 0;

    if (*lineptr == NULL || *n == 0) {
        // Allocate initial memory for lineptr if it's NULL or size is 0
        *lineptr = malloc(BUFFER_SIZE);
        *n = BUFFER_SIZE;
    }

    do {
        /* read from file descriptor */
        r = read(fileno(stream), buffer, *n);
        /* verifcation */
        if (r == -1)
            return (-1);
        /* if no content to read */
        if (r == 0)
            break;
        /* 
         * if the space avalaible is not enought, increase the size. 
         * This reservation allows to copy all read data
         */
        if (line_position + r >= *n)
        {
            /* *n *= *n; */
            /* 
             * reserve the memory space needed to copy data 
             * from buffer to lineptr once only 
             */
            *n += r;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL)
                return (-1);
        }
        /* copy buffer elements into lineptr */
        while (index < r)
        {
            /* check for end of line */
            if (buffer[buffer_position] == '\n')
            {
                /* Null-terminate the line */
                (*lineptr)[line_position++] = '\0';
                /* 
                 * if End of Line exit the two loops by setting 
                 * should_break to True 
                 */
                should_break = 1;
                break;
            }
            else
            {
                /* copy each character from buffer to lineptr */
                (*lineptr)[line_position] = buffer[buffer_position];
                buffer_position++;
                line_position++;
                /* Increment the character count including the delimiter */
                char_count++;
            }
        }
        /*
         * returns the buffer position to 0 
         * if it reaches the end of the buffer 
         */
        if (buffer_position >= r)
            buffer_position = 0;
        index++;
    } while (r > 0 && !should_break);

    /* No more input and nothing read */
    if (line_position == 0 && r == 0)
        return (0);
    return (char_count);
}
