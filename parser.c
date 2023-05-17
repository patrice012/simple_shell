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

int parse_cmd(char *cmd, char **argv)
{
    int argc = 0; /* Number of arguments */
    char *arg; /* Current argument */
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

/**
 * parse_path - Parse the PATH environment variable to find the executable path
 * @cmd: The command name
 *
 * Return: The absolute path to the executable if found, otherwise a duplicate
 * of the command name.
 */

/* Test output : PATH
 * Input: /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin
 * Output:
 *     /usr/local/sbin
 *     /usr/local/bin
 *     /usr/sbin
 *     /usr/bin
 *     /sbin
 */

char *parse_path(char *cmd)
{
    char *path = _get_env("PATH");
    /* copy the path value*/
    char *path_copy = strdup(path);
    char *token, *abs_path;

    if (path_copy == NULL) {
        return (strdup(cmd));
    }
    token = strtok(path_copy, ":");
    while (token != NULL) {
        /* 
         *using length of token + length of cmd + 2 (1 for / and 1 for '\0')
         *because the output has this format token + / + cmd + '\0'
         */
        abs_path = malloc(_strlen(token) + _strlen(cmd) + 2);
        /* sprintf(abs_path, "%s/%s", token, cmd);*/
        build_abs_path(token, cmd, abs_path);

        /* if file exist and is an executable file */
        if (access(abs_path, X_OK) == 0) {
            // free(path_copy);
            return (abs_path);
        }

        // free(abs_path);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return strdup(cmd);
}
