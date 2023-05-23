#include "header.h"

extern char **environ;

/**
 * _get_env_variable - check if variable is an environement varaible
 * @var_name: varable name
 * @environ: environ array
 * Return: index of the varaible if exist and -1 if not
 */

int _is_env_variable (char *var_name, char **environ)
{
    int index = 0, len = 0;

    if (!var_name || !environ)
        return (-1);

    len = _strlen(var_name);

    while (environ[index])
    {
        /* compare each element in array to name */
        if (_strncmp(environ[index], var_name, len) == 0)
            {
                return (index);
            }
        index++;
    }
    return (-1);
} 




/**
 * _getenv - Gets an environmental variable value if exist.
 *
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *         Otherwise, value of environmental variable.
 */

char *_get_env(char *arg)
{
    int len, index;

    if (arg == NULL || environ == NULL)
        return (NULL);

    len = _strlen(arg);
    index = _is_env_variable(arg, environ);

    if (index == -1)
        return (NULL);

    /* Extract the value after "arg=" */
    /* 
     *environ is of type char *environ[] so environ[index]
     *give access to element at [index] postion in array
     *this value is also of type char *str so str[len] give access 
     *to the element that follow the str => environ[index][len]
     */
    if (environ[index][len] == '=')
    {
        /* return pointer to the first byte after = */
        return (environ[index] + len + 1);
    }
    return (NULL);
}


/**
 * free_env - frees the memory that the environment copy
 * takes.
 */
void free_env(void)
{
    free_array(environ);
}

