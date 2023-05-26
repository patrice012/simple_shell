#include "header.h"

/**
 * execute - checks whether a command is built-in or system command and
 * calls the relevant function
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void execute(char *line_buffer)
{
	int n, j, cmd_status;
	char *argv[MAX_ARGS_COUNT + 1], *cmd, *rest, sep;/* *rest, sep*/

	rest = line_buffer;
	while (rest != NULL)
	{
		split_cmd(rest, &sep, &cmd, &rest);
		cmd_status = 0, hist++;
		n = parse_cmd(cmd, argv);
		if (n == 0)
			break;
		/*handle_variables(argv);*/
		/*handle_aliases(argv);*/

		cmd_status = check_for_builtin(argv, line_buffer);
		if (cmd_status == 1)
			cmd_status = execute_system_cmd(argv, n);

		for (j = 0; j < n; j++)
			free(argv[j]);

		status_code = cmd_status;
		if (cmd_status == 0 || cmd_status == 127 || cmd_status == 126)
			break;
		if ((sep == '|' && cmd_status == 0) || (sep == '&' && cmd_status != 0))
			break;
		else if (sep == '#')
			break;
	}
}

/**
 * _is_valid_cmd - check if the command is found
 * or if the path is correct
 * @argv: array of strings storing the command and it's arguments
 * @prog_path: program path
 * Return: 0 for failure and 1 for success
 */

int _is_valid_cmd(char *prog_path, char **argv)
{
	struct stat st;

	if ((_strcmp(prog_path, argv[0]) == 0 && _strncmp(prog_path, "./", 2) != 0 &&
		(prog_path[0] != '/' && _strncmp(prog_path, "../", 3) != 0)) ||
		stat(prog_path, &st) != 0)
		return (0);
	return (1);
}


/**
 * execute_system_cmd - runs a command and waits for it to finish
 *
 * @argv: array of strings storing the command and it's arguments
 * @n: number of arguments in argv
 *
 * Return: exit status code of child process
 */
int execute_system_cmd(char **argv, int n)
{
	char *prog_path;
	int child_pid, child_status = -1, j;

	prog_path = find_in_path(argv[0]);
	if (_is_valid_cmd(prog_path, argv) == 0)
	{
		free(prog_path);
		error_127(argv[0]);
		return (127);
	}
	else if (access(prog_path, X_OK) == -1)
	{
		free(prog_path);
		error_126(argv[0]);
		return (126);
	}

	child_pid = create_process();

	if (child_pid == 0)
	{
		if (execve(prog_path, argv, environ) == -1)
		{
			perror(prog_name);
			for (j = 0; j < n; j++)
				free(argv[j]);
			free(prog_path);

			_exit(1);
		}
	}
	else if (child_pid > 0)
		wait(&child_status);

	free(prog_path);
	return (child_status / 256);
}

