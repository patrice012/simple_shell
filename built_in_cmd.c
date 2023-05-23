#include "header.h"

/**
 * shell_exit - Implement the exit built-in, that exits the shell
 * Return: None
 */

/*
 * Usage: exit status
 * Exit the shell with a status code of 0 (success)
 */

void shell_exit(char **av)
{
    /* _exit(0); */
    /* get exit status value */
    char *_status = *(av + 1);
    /* convert into integer */
    int status = _atoi(_status);
    if (status)
        exit(status);
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


/**
 * _setenv - Sets the value of an environment variable or
 * creates a new one if it doesn't exist.
 * @variable: The name of the environment variable.
 * @value: The value to be assigned to the environment variable.
 * 
 * Return: Returns 0 on success or -1 on failure.
 */

/*
 * Usage: setenv VARIABLE VALUE
 */

int _setenv(char *variable, char *value)
{
    int index = _is_env_variable(variable)
    if (variable == NULL || value == NULL)
        return (-1);

    
}
