#include "header.h"


/*
 * Test output
 * Input: "ls -l"
 * Output:
 * argv[0] = "ls"
 * argv[1] = "-l"
 * Input: "cd /tmp"
 * Output:
 * argv[0] = "cd"
 * argv[1] = "/tmp"
 * Input: "pwd"
 * Output:
 * argv[0] = "pwd"
 * Input: "echo hello world"
 * Output:
 * argv[0] = "echo"
 * argv[1] = "hello"
 * argv[2] = "world"
 */


/**
 * parse_cmd - extracts the command and arguments
 *
 * @cmd: pointer to a string
 * @argv: array of pointers to strings
 *
 * Return: number of tokens
 */
int parse_cmd(char *cmd, char **argv)
{
	int argc = 0, i = 0, len = 0, empty_str = 0;
	char c, *arg, quote = '\0';

	arg = malloc(sizeof(char) * (_strlen(cmd) + 1));
	for (i = 0; (c = cmd[i]) != '\0'; i++)
	{
		if ((c == '\'' || c == '\"'))
		{
			if (!quote)
				quote = c;
			else if (quote == c)
				quote = '\0', empty_str = 1;
		}
		else if ((c == ' ' || c == '\n' || c == '\t') && !quote)
		{
			if (len || empty_str)
			{
				arg[len] = '\0';
				argv[argc++] = _strdup(arg);
				len = 0, empty_str = 0;
			}
		}
		else
		{
			if (c == '\\' && cmd[i + 1] != '\0')
				c = cmd[++i];
			arg[len++] = c;
			empty_str = 0;
		}
	}
	if (len || empty_str)
	{
		arg[len] = '\0';
		argv[argc++] = _strdup(arg);
	}

	argv[argc] = NULL;
	free(arg);
	return (argc);
}


/**
 * split_cmds - spilts the buffer containing commands into two strings
 *
 * @buffer: a string that contains the commands
 * @separator: the separator that should be used to split the buffer
 * @cmd: a pointer to the first command
 * @rest: a pointer to the rest of the string
 *
 * Note: this function separates the BUFFER by ';', '||' or '&&'
 * and sets SEPARATOR char to the one found then it assigns the
 * first half (first command) to CMD pointer
 * and assigns the rest of the string to REST pointer.
 *
 * If no SEPARATOR can be found in BUFFER, the fucntion assigns the
 * whole BUFFER into CMD and REST is pointing to NULL
 */
void split_cmds(char *buffer, UNUSED char *separator, char **cmd, char **rest)
{
	int i;
	char quote = '\0';

	*cmd = buffer;
	*separator = '\0';
	*rest = NULL;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\'' || buffer[i] == '\"')
		{
			if (!quote)
				quote = buffer[i];
			else if (quote == buffer[i])
				quote = '\0';
		}

		if (!((buffer[i] == ';' || _strncmp(buffer + i, "||", 2) == 0 ||
			_strncmp(buffer + i, "&&", 2) == 0 || buffer[i] == '#') && !quote))
			continue;

		if (buffer[i] == '#' && i > 0 && buffer[i - 1] != ' ')
			continue;

		*separator = buffer[i];
		*rest = buffer + i + 1;

		if ((_strncmp(buffer + i, "||", 2) == 0 ||
					_strncmp(buffer + i, "&&", 2) == 0))
		{
			buffer[i + 1] = ' ';
			*rest += 1;
		}
		buffer[i] = '\0';

		break;
	}
}



/**
 * parse_path - Parse the PATH environment variable to find the executable path
 * @cmd: The command name
 *
 * Return: The absolute path to the executable if found, otherwise a duplicate
 * of the command name.
 */

/*
 * Test output : PATH
 * Input: /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin
 * Output:
 *     /usr/local/sbin
 *     /usr/local/bin
 *     /usr/sbin
 *     /usr/bin
 *     /sbin
 */

char *parse_path(char *cmd)
{
	char *path = getenv("PATH"); /* _getenv */
	/* copy the path value*/
	char *path_copy = strdup(path), *token, *abs_path;
	struct stat st;

	if (cmd == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	if (path_copy == NULL)
		return (strdup(cmd));
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		/*
		 * using length of token + length of cmd + 2 (1 for / and 1 for '\0')
		 * because the output has this format => token + / + cmd + '\0'
		 */
		abs_path = malloc(_strlen(token) + _strlen(cmd) + 2);
		/*create_abs_path(token, cmd, abs_path);*/
		snprintf(abs_path, (_strlen(token) + _strlen(cmd) + 2), "%s/%s", token, cmd);
		/* if file exist and is an executable file */
		if (access(abs_path, X_OK) == 0)
		{
			token = NULL;
			free(path_copy);
			return (abs_path);
		}
		/*free(abs_path);*/
		free(abs_path);
		token = strtok(NULL, ":");
	}
	free(path_copy), free(token);
	/* check if command itself is a file_path that exists */
	if (stat(cmd, &st) == 0)
		return (cmd);
	return (NULL);
}
