#include "header.h"

/**
 * format_tilde - search string for home/@USERNAME
 *			            if exists, change it to ~.
 * @envp: env variable
 * @str: string to search for.
 * Return: string
 */
char *format_tilde(char *str, char **envp)
{
	int len = 0, path_len = 0;
	char *home, *username, *result, *tmp;

	username = _get_env("USERNAME", envp);

	if (username == NULL)
		return (NULL);

	len = _strlen(username);
	home = (char *)malloc(sizeof(char) * (7 + len));
	home[0] = '\0';

	if (home == NULL)
		return (NULL);

	_strcat(home, "/home/");
	_strcat(home, username);
	len = _strlen(home);
	path_len = _strlen(str);

	result = (char *)malloc(sizeof(char) * (len + path_len + 1));
	result[0] = '\0';

	if (result == NULL)
		return (NULL);

	if (_strncmp(str, home, len) == 0)
	{
		_strcat(result, "~");
		tmp = _substr(str, len + 1, path_len);
		_strcat(result, tmp);
		free(tmp);
	}

	free(home);
	return (result);
}

/**
 * change_dir - changes the directory of the process
 *
 * @dir: string - new directory
 * @envp: env variable
 * Return: 0 on sucess, 1 on failure
 */
int change_dir(char *dir, char **envp)
{
	char cwd[PATH_MAX];

	if (dir == NULL || *dir == '\0')
	{
		dir = _strdup(_get_env("HOME", envp));
		if (dir == NULL)
			dir = _strdup(_get_env("PWD", envp));
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _strdup(_get_env("OLDPWD", envp));
		if (dir == NULL)
			dir = _strdup(_get_env("PWD", envp));

		print_str(dir);
		print_str("\n");
	}
	else
		dir = _strdup(dir);
	if (_setenv("OLDPWD", _get_env("PWD", envp), envp) == -1)
	{
		print_error("Failed to update OLDPWD env variable");
		return (2);
	}

	if (chdir(dir) == -1)
	{
		/*error_cd(dir);*/
		free(dir);
		return (2);
	}

	free(dir);
	if (_setenv("PWD", getcwd(cwd, sizeof(cwd)), envp) == -1)
	{
		print_error("Failed to update PWD env variable");
		return (2);
	}

	return (0);
}

/**
 * alias - alias built in command to print and set aliases
 *
 * @tokens: a tokenized string of commands and arguments
 * @envp: env variable
 * Return: 0 on sucess, 1 on fialure
 */
int alias(char **tokens, char **envp)
{
	int i, status = 0;

	if (tokens[1] == NULL)
		return (print_alias(NULL, envp));
	for (i = 1; tokens[i] != NULL; i++)
		if (_strchr(tokens[i], '=') == NULL)
			status |= print_alias(tokens[i], envp);
		else
			status |= set_alias(tokens[i], envp);
	return (0);
}
