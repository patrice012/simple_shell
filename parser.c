#include "header.h"

/**
 * parse_cmd - Parses a command string and populates an array of arguments.
 * The `parse_cmd` function tokenizes the command string `cmd` based on
 * spaces, tabs, and newlines. It stores the extracted arguments in the
 * `argv` array, which is passed as a parameter.
 * 
 * @cmd: The command string to parse.
 * @argv: The array of arguments to populate.
 * Return: The number of arguments parsed.
 */


/*
 * Test output
 * Input: "ls -l"
 * Output:
 * argv[0] = "ls"
 * argv[1] = "-l"
 * 
 * Input: "cd /tmp"
 * Output:
 * argv[0] = "cd"
 * argv[1] = "/tmp"
 * 
 * Input: "pwd"
 * Output:
 * argv[0] = "pwd"
 * 
 * Input: "echo hello world"
 * Output:
 * argv[0] = "echo"
 * argv[1] = "hello"
 * argv[2] = "world"
 */
    int parse_cmd(char *cmd, char *argv)
    {
    int argc = 0; /* Number of arguments */
    char arg; /* Current argument */
    char token; /* Tokenized substring */

    arg = strtok(cmd, " \t\n"); /* Get the first argument */

    while (arg != NULL)
    {
        argv[argc] = _strdup(arg); /* Add argument to array */
        argc++;
        arg = strtok(NULL, " \t\n"); /* Get the next argument */
    }
    argv[argc] = NULL; /* Set the last element of the array to NULL */
    return (argc); /* Return the number of arguments */
    }
