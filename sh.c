#include "header.h"

/**
 * run_cmd - checks whether a command is built-in or system command and
 * calls the relevant function
 * @argv: array of env variable
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void run_cmd(char *line_buffer, char **argv)
{
	int n, j, cmd_status;
	char *av[MAX_ARGS_COUNT + 1], *cmd, *rest, sep;

	rest = line_buffer;

	while (rest != NULL)
	{
		split_cmds(rest, &sep, &cmd, &rest);
		cmd_status = 0;
		n = parse_cmd(cmd, av);
		if (n == 0)
			break;
		/*handle_variables(av);*/
		/*handle_aliases(av);*/
		cmd_status = run_built_in_command(av, line_buffer);
		if (cmd_status == 0)
			cmd_status = run_sys_cmd(av, n, argv);
		if (cmd_status == -1)
			break;
		for (j = 0; j < n; j++)
			free(av[j]);
		status_code = cmd_status;
		if (sep == '|' && cmd_status == 0)
			break;
		else if (sep == '&' && cmd_status != 0)
			break;
		else if (sep == '#')
			break;
	}
}


/**
 * run_sys_cmd - runs a command and waits for it to finish
 *
 * @av: array of strings storing the command and it's arguments
 * @n: number of arguments in av
 * @argv: arg vector
 * Return: exit status code of child process
 */
int run_sys_cmd(char **av, int n, char **argv)
{
	char *_path;
	struct stat st;
	int child_pid, child_status = -1, j;

	_path = parse_path(av[0]);
	if (_path == NULL)
	{
		print_error(argv[0]), print_error(": No such file or directory\n");
		return (-1);
	}
	if ((_strcmp(_path, av[0]) == 0 && _strncmp(_path, "./", 2) != 0 &&
	(_path[0] != '/' && _strncmp(_path, "../", 3) != 0)) || stat(_path, &st) != 0)
	{
		free(_path);
		return (127);
	}
	else if (access(_path, X_OK) == -1)
	{
		free(_path);
		return (126);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		free(_path), perror(argv[0]);
	}
	if (child_pid == 0)
	{
		if (execve(_path, av, environ) == -1)
		{
			perror(program_name);
			for (j = 0; j < n; j++)
				free(av[j]);
			free(_path);
			_exit(1);
		}
	}
	else if (child_pid > 0)
		wait(&child_status);
	return (child_status / 256);
}



/**
 * run_built_in_command - run  built-in commands
 * @av: array of command arguments
 * @line_buffer: initial command entered
 * Return: 0 for success and 1 for failure
 */

int run_built_in_command(char **av, UNUSED char *line_buffer)
{
	int success = 1;/* should be change to 1 for success */

	if (_strcmp(av[0], "exit") == 0)
		shell_exit(av);
	else if (_strcmp(av[0], "env") == 0)
		shell_env();
	else if (_strcmp(av[0], "setenv") == 0)
		_setenv(av[1], av[2]);
	else if (_strcmp(av[0], "unsetenv") == 0)
		_unsetenv(av[1]);
	else if (_strcmp(av[0], "cd") == 0)
		change_dir(av[1]);
	else if (_strcmp(av[0], "alias") == 0)
		alias(av);
	else
		success = 0;
	return (success);
}

