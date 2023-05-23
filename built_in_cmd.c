#include "header.h"

int _putenv(char *str);

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
 * _unsetenv - unsets an environmental variable
 *
 * @var_name: var_name of variable to be unset.
 *
 * Return: 0 on success, -1 on fail
 *
 * note: the algorithm unsets by shifting all
 *        successive entries back one element.
 */

int _unsetenv( char *variable) {
    if (variable == NULL) {
        print_error("unsetenv: Invalid argument\n");
        return -1;
    }
    
    int result = _putenv((char *)variable);
    
    if (result != 0) {
        print_error("unsetenv: Failed to unset the environment variable\n");
        return -1;
    }
        return 0;
}
    

/**
 * _setenv - Sets the value of an environment variable or
 * creates a new one if it doesn't exist.
 * @variable: The var_name of the environment variable.
 * @value: The value to be assigned to the environment variable.
 * 
 * Return: Returns 0 on success or -1 on failure.
 */

/*
 * Usage: setenv VARIABLE VALUE
 */

int _setenv( char *variable,  char *value) 
{
    int result;
    char *env;

    if (variable == NULL || value == NULL) {
        print_error("setenv: Invalid arguments\n");
        return -1;
    }

    /* Update or create the environment variable */
    /* +2 for '=' and '\0' */
    env = malloc(_strlen(variable) + _strlen(value) + 2);
    if (env == NULL) {
        print_error("setenv: Memory allocation failed");
        return -1;
    }
    
    /* format: variable=value */
    _format(variable, value, env, "=");
    result = _putenv(env);
    
    if (result != 0) {
        print_error("setenv: Failed to set the environment variable\n");
        free(env);
        return -1;
    }
    
    return 0;
}

/**
 * _putenv - Sets the variable of an environment
 * @str: The var_name of the environment variable.
 * 
 * Return: Returns 0 on success or -1 on failure.
 */

/*
 * Usage: setenv VARIABLE VALUE
 */

int _putenv(char *str) {
    /* Invalid argument or missing '=' character */
    if (str == NULL || str[0] == '\0' || strchr(str, '=') == NULL) {
        return -1;
    }

    /* Find the length of the input string */
    size_t len = _strlen(str);

    /* Search for the '=' character to determine the key-value separation */
    const char *sep = _strchr(str, '=');
    if (sep == NULL) {
        return -1; /* Invalid argument, missing '=' character */
    }

    /* Calculate the length of the key and value */
    size_t key_len = sep - str;
    size_t value_len = len - key_len - 1;

    /* Create a copy of the input string*/
    char *copy = malloc((len + 1) * sizeof(char));
    if (copy == NULL) {
        return -1; /* Failed to allocate memory*/
    }
    _strcpy(copy, str);

    /* Update or add the environment variable*/
    char **new_environ = NULL;
    int found = 0;
    size_t environ_len = _get_env_len();
    char **ep;

    /* Allocate memory for the updated environment */
    new_environ = malloc((environ_len + 2) * sizeof(char *));
    if (new_environ == NULL) {
        free(copy);
        return -1; /* Failed to allocate memory */
    }

    /* Copy the existing environment variables */
    size_t i;
    for (i = 0; i < environ_len; i++) {
        new_environ[i] = environ[i];
        if (_strncmp(environ[i], str, key_len) == 0 && environ[i][key_len] == '=') {
            /* Found an existing variable, update its value*/
            free(environ[i]);
            environ[i] = copy;
            found = 1;
        }
    }

    if (!found) {
        /* The variable doesn't exist, add it to the environment */
        new_environ[environ_len] = copy;
        new_environ[environ_len + 1] = NULL;
        environ = new_environ;
    } else {
        /* Free the new environment if variable was found */
        free(new_environ);
    }

    return 0; /* Success */
}
