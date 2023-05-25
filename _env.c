#include "header.h"

/**
 * _is_env_variable - check if variable is an environement varaible
 * @var_name: varable name
 * Return: index of the varaible if exist and -1 if not
 */

int _is_env_variable(char *var_name)
{
	int index = 0, len = 0;

	if (!var_name || !environ)
		return (-1);
	len = _strlen(var_name);
	while (environ[index])
	{
		/* compare len=n characters of each element in array to name */
		if (_strncmp(environ[index], var_name, len) == 0)
			return (index);
		index++;
	}
	return (-1);
}


/**
 * _get_env - Gets an environmental variable value if exist.
 * @arg: the name of the environmental variable.
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
	index = _is_env_variable(arg);

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
		/*
		 * return pointer to the first byte after =
		 * environ[index] + len + 1 calculates a new memory address
		 * by moving the pointer len + 1 elements forward
		 * after environ[index] first byte
		 */
		return (environ[index] + len + 1);
	}
	return (NULL);
}



/**
 * _get_env_len - gets the number of variables
 *              inside an environment.
 * Return: number of variables.
 */
int _get_env_len(void)
{
	int count = 0;

	while (environ[count] != NULL)
		count++;
	return (count);
}



/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	char **env;
	size_t name_len = _strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
