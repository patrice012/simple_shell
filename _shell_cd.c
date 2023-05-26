#include "main.h"


/**
 * change_directory - changes the directory of the process
 *
 * @dir: string - new directory
 *
 * Return: 0 on sucess, 1 on failure
 */
int change_directory(char *dir)
{
	char cwd[PATH_MAX];

	if (dir == NULL || *dir == '\0')
	{
		dir = _strdup(_getenv("HOME"));
		if (dir == NULL)
			dir = _strdup(_getenv("PWD"));
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _strdup(_getenv("OLDPWD"));
		if (dir == NULL)
			dir = _strdup(_getenv("PWD"));

		print_str(dir);
		print_str("\n");
	}
	else
		dir = _strdup(dir);
	if (_setenv("OLDPWD", _getenv("PWD")) == -1)
	{
		print_err("Failed to update OLDPWD env variable");
		return (2);
	}
	if (chdir(dir) == -1)
	{
		error_cd(dir);
		free(dir);
		return (2);
	}
	free(dir);
	if (_setenv("PWD", getcwd(cwd, sizeof(cwd))) == -1)
	{
		print_err("Failed to update PWD env variable");
		return (2);
	}
	return (0);
}

