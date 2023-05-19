#include "header.h"

/**
 * shell_exit - Implement the exit built-in, that exits the shell
 * Return: None
 */

/*
 * Usage: exit
 * Exit the shell with a status code of 0 (success)
 */

void shell_exit(void)
{
    // _exit(0);
    exit(0);
}

/**
 * shell_env - display the current environment variables in a shell.
 * Return: None
 */

/*
 * Usage: env
 */


void shell_env(void)
{
    int i = 0;

    while (environ[i] != NULL)
    {
        print_str(environ[i]);
        print_str("\n");
        i++;
    }
}
