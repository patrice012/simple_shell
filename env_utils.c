#include "header.h"

/* local helper function headers */
int _get_env_len(void);

/**
 * setup_env - Makes a copy of the original environment.
 * Return: 0 if successful, -1 if failed.
 */
int setup_env(void)
{
	int env_cnt, var_cnt, i;
	char **new_environ;

	env_cnt = _get_env_len();

	new_environ = malloc(sizeof(char *) * (env_cnt + 1));

	if (new_environ == NULL)
	{
		free(new_environ);
		return (-1);
	}

	for (i = 0; i < env_cnt; i++)
	{
		for (var_cnt = 0; environ[i][var_cnt] != '\0'; var_cnt++)
			;

		new_environ[i] = malloc(sizeof(char) * (var_cnt + 1));

		_memcpy(new_environ[i], environ[i], sizeof(char) * (var_cnt + 1));

		if (new_environ[i] == NULL)
		{
			free_env();
			return (-1);
		}
	}

	new_environ[i] = NULL;

	environ = new_environ;

	return (0);
}




/**
 * _get_env - Gets an environmental variable.
 *
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *		   Otherwise, value of environmental variable.
 */
char *_get_env(char *var)
{
	int idx, len;

	if (var == NULL)
		return (NULL);

	len = _strlen(var);

	if (environ != NULL)
	{
		for (idx = 0; environ[idx]; idx++)
		{
			if (_strncmp(var, environ[idx], len) == 0 && environ[idx][len] == '=')
				return (environ[idx] + len + 1);
		}
	}

	return (NULL);
}



/**
 * _get_env_len - gets the number of variables
 *				inside an environment.
 * Return: number of variables.
 */
int _get_env_len(void)
{
	int count = 0;

	while (environ[count] != NULL)
		count++;
	return (count);
}

