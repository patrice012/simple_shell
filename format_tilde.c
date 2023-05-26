#include "main.h"


/**
 * format_tilde - search string for home/@USERNAME
 *			            if exists, change it to ~.
 *
 * @str: string to search for.
 * Return: string
 */
char *format_tilde(char *str)
{
	int len = 0, path_len = 0;
	char *home, *username, *result, *tmp;

	username = _getenv("USERNAME");

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
