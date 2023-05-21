#include "header.h"


#define MAX_SIZE 20



#define BUFFER_SIZE 100
#define READ_SIZE 5


// ssize_t getline(char **lineptr, size_t *n, FILE *stream);

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
    static char buffer[BUFFER_SIZE];
    // static int buffer_position = 0;
    int buffer_position = 0;
    ssize_t line_position = 0;
    ssize_t r = 0, index = 0;
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

        /* if the space avalaible is not enought, increase the size */
        if (line_position + 1 >= *n)
        {
            /* *n += *n; */
            /* reserve the memory space needed to copy data from buffer to lineptr once only */
            *n += *n;
            *lineptr = realloc(*lineptr, *n);
            if (*lineptr == NULL)
                return (-1);
        }
        
        /* copy buffer elements into lineptr */
        while (buffer[buffer_position])
        {
            /* check for end of line */
            if (buffer[buffer_position] == '\n')
            {
                /* Null-terminate the line */
                (*lineptr)[line_position] = '\0';
                /* if End of Line exit the two loops by setting should_break to True */
                should_break = 1;
                break;
            }
            else
            {
                /* if no more space in lineptr increase the size */
                
                 if (line_position + 1 >= *n)
                  {
                      *n += *n;
                      *lineptr = realloc(*lineptr, *n);
                  }
                 

                /* copy each character in buffer into lineptr */
                (*lineptr)[line_position] = buffer[buffer_position];
                buffer_position++;
                line_position++;
            }
        }
        // Reset buffer position when it reaches the end
        if (buffer_position >= r) {
            buffer_position = 0;
        }
    } while (r > 0 && !should_break);

    /* No more input and nothing read */
    if (line_position == 0 && r == 0) {
        return (-1);
    }

    return (line_position);
}



















// int main() {
//     char *line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     while ((read = getline(&line, &len, stdin)) != -1) {
//         // Process the line as needed
//         printf("Line: %s\n", line);
//         printf("Read: %ld\n", read);
//         // printf("Line:");
//     }


//     free(line);
//     return 0;
// }




ssize_t __getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static int buffer_pos = 0;
    static int buffer_size = 0;
    ssize_t line_pos = 0;
    char ch;

    if (*lineptr == NULL || *n == 0) {
        // Allocate initial memory for lineptr if it's NULL or size is 0
        *lineptr = malloc(BUFFER_SIZE);
        *n = BUFFER_SIZE;
    }

    while (1) {
        if (buffer_pos >= buffer_size) {
            // Read more characters into the buffer
            buffer_size = read(fileno(stream), buffer, READ_SIZE);
            buffer_pos = 0;

            if (buffer_size == 0) {
                // End of input reached
                break;
            }
        }

        ch = buffer[buffer_pos++];
        if (ch == '\n') {
            // End of line reached
            if (line_pos + 1 >= *n) {
                // Resize lineptr if it's not large enough to hold the line
                *n *= 2;
                *lineptr = realloc(*lineptr, *n);
            }
            (*lineptr)[line_pos++] = '\0';  // Null-terminate the line
            break;
        }

        if (line_pos + 1 >= *n) {
            // Resize lineptr if it's not large enough to hold the next character
            *n *= 2;
            *lineptr = realloc(*lineptr, *n);
        }
        (*lineptr)[line_pos++] = ch;
    }

    if (line_pos == 0 && buffer_size == 0) {
        // No more input and nothing read
        return -1;
    }

    return line_pos;
}
