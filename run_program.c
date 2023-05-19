#include "header.h"

/**
 * run_cmd - checks whether a command is built-in or system command and
 * calls the relevant function
 * @av: program argument vector
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void run_cmd(char *line_buffer, char **av)
{
    int n, j, cmd_status;
    char *argv[MAX_ARGS_COUNT + 1] = { NULL }, *cmd = NULL, sep;
    // char *rest;

    /* copy the value of line_buffer into rest */
    // rest = line_buffer;
    /* set temporary cmd to all the line_buffer */
    cmd = strdup(line_buffer);
    
    /* split cmd into array by using space as delimiter */
    n = parse_cmd(cmd, argv);
    if (n == 0)
    {
        free_array(argv);
        // free_pointer(cmd);
        return;
    }
    /*handle_variables(argv);*/
    /*handle_aliases(argv);*/

    /* try to run built-in commands */
    cmd_status = run_built_in_command(argv, line_buffer);

    if (cmd_status == 0) /* mean not built-in commands ==> 1 succes */
        /* run system command */
    {
        // free_pointer(cmd);
        cmd_status = run_sys_cmd(argv, n, av);
    }
}


/**
 * run_built_in_command - run  built-in commands
 * @argv: array of command arguments
 * @line_buffer: initial command entered
 * Return: 0 for success and 1 for failure
 */

int run_built_in_command(char **argv, char *line_buffer)
{
    int cmd_status, success = 0;/* should be change to 1 for success */

    if (_strcmp(argv[0], "exit") == 0)
        // cmd_status = exit_shell(line_buffer, argv);
        shell_exit();

    else if (_strcmp(argv[0], "env") == 0)
    //     _env();
        shell_env();
    // else if (_strcmp(argv[0], "setenv") == 0)
    //     cmd_status = (_setenv(argv[1], argv[2]) ? 2 : 0);
    // else if (_strcmp(argv[0], "unsetenv") == 0)
    //     cmd_status = (_unsetenv(argv[1]) ? 2 : 0);
    // else if (_strcmp(argv[0], "cd") == 0)
    //     cmd_status = change_dir(argv[1]);
    // else if (_strcmp(argv[0], "alias") == 0)
    //     cmd_status = alias(argv);
    // else
    //     success = 0;
    return (success);
}


/**
 * run_sys_cmd - runs a command and waits for it to finish
 *
 * @argv: array of strings storing the command and it's arguments
 * @n: number of arguments in argv
 * @av: program argument vector
 * Return: exit status code of child process
 */
int run_sys_cmd(char **argv, int n, char **av)
{
    char *prog_path;
    int child_pid, child_status = -1, j;
    struct stat st;

    prog_path = parse_path(argv[0]);
    if (prog_path == NULL)
    {
        perror(*(av + 0));
        return (-1); /* failure or error condition in the code */
    }

    child_pid = fork();
    if (child_pid == -1)
            perror(*(av + 0));

    if (child_pid == 0)
    {
        if (execve(prog_path, argv, environ) == -1)
        {
            perror(*(av + 0));
            for (j = 0; j < n; j++)
                free(argv[j]);
            free(prog_path);
            _exit(1);
        }
    }
    else if (child_pid > 0)
        wait(&child_status);

    free(prog_path);
    return (child_status / 256);
}
