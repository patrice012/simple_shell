#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 20



#define BUFFER_SIZE 4096
#define READ_SIZE 10


ssize_t getline(char **lineptr, size_t *n, FILE *stream);

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

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    static char *buffer[BUFFER_SIZE];
    ssize_t r;

    r = read()
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        // Process the line as needed
        printf("Line: %s\n", line);
    }

    free(line);
    return 0;
}




// ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
//     static char buffer[BUFFER_SIZE];
//     static int buffer_pos = 0;
//     static int buffer_size = 0;
//     ssize_t line_pos = 0;
//     char ch;

//     if (*lineptr == NULL || *n == 0) {
//         // Allocate initial memory for lineptr if it's NULL or size is 0
//         *lineptr = malloc(BUFFER_SIZE);
//         *n = BUFFER_SIZE;
//     }

//     while (1) {
//         if (buffer_pos >= buffer_size) {
//             // Read more characters into the buffer
//             buffer_size = read(fileno(stream), buffer, READ_SIZE);
//             buffer_pos = 0;

//             if (buffer_size == 0) {
//                 // End of input reached
//                 break;
//             }
//         }

//         ch = buffer[buffer_pos++];
//         if (ch == '\n') {
//             // End of line reached
//             if (line_pos + 1 >= *n) {
//                 // Resize lineptr if it's not large enough to hold the line
//                 *n *= 2;
//                 *lineptr = realloc(*lineptr, *n);
//             }
//             (*lineptr)[line_pos++] = '\0';  // Null-terminate the line
//             break;
//         }

//         if (line_pos + 1 >= *n) {
//             // Resize lineptr if it's not large enough to hold the next character
//             *n *= 2;
//             *lineptr = realloc(*lineptr, *n);
//         }
//         (*lineptr)[line_pos++] = ch;
//     }

//     if (line_pos == 0 && buffer_size == 0) {
//         // No more input and nothing read
//         return -1;
//     }

//     return line_pos;
// }
