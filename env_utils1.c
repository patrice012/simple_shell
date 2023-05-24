#include "header.h"


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
