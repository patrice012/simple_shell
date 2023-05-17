#include "header.h"

/**
 * _getenv - Gets an environmental variable.
 *
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *         Otherwise, value of environmental variable.
 */

char *_get_env(char *arg)
{
    /* get arg length */
    int len, index;

    if (arg == NULL || environ == NULL)
        return (NULL);
    len = _strlen(arg);
    /* compare each element in array to arg */
    for(index = 0; environ[index]; index++)
    {
        if (_strncmp(arg, environ[index], len) == 0)
        {
            /* Extract the value after "arg="*/
            /* 
             *environ is of type char *environ[] so environ[index]
             *give access to element at index postion in array
             *this value is also of type char *str so str[len] give access 
             *to the element that follow the str => environ[index][len]
             */
            if (environ[index][len] == '=')
            {
                /* return pointer to the first byte after = */
                return (environ[index] + len + 1);
            }
        }
    }
    return (NULL);
}


/**
 * free_env - frees the memory that the environment copy
 *                                                takes.
 */
void free_env(void)
{
    int i;

    for (i = 0; environ[i] != NULL; i++)
        free(environ[i]);
    free(environ);
}
