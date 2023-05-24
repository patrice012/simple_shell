#include "header.h"

/**
 * run_cmd - checks whether a command is built-in or system command and
 * calls the relevant function
 * @argv: program argument vector
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void run_cmd(char *line_buffer, char **argv)
{
	int n, cmd_status;
	char *av[MAX_ARGS_COUNT + 1] = { NULL }, *cmd = NULL;
	/* set temporary cmd to all the line_buffer */

	cmd = strdup(line_buffer);
	/* split cmd into array by using space as delimiter */
	n = parse_cmd(cmd, av);
	if (n == 0)
	{
		free_array(av);
		/* free_pointer(cmd);*/
		return;
	}
	/*handle_variables(av);*/
	/*handle_aliases(av);*/
	/* try to run built-in commands */
	cmd_status = run_built_in_command(av, line_buffer);

	if (cmd_status == 0) /* mean not built-in commands ==> 1 succes */
	{
		/* free_pointer(cmd);*/
		cmd_status = run_sys_cmd(av, n, argv);
	}
}


/**
 * run_built_in_command - run  built-in commands
 * @av: array of command arguments
 * @line_buffer: initial command entered
 * Return: 0 for success and 1 for failure
 */

int run_built_in_command(char **av, UNUSED char *line_buffer)
{
	int success = 1;/* cmd_status should be change to 1 for success */

	if (_strcmp(av[0], "exit") == 0)
		shell_exit(av);
	else if (_strcmp(av[0], "env") == 0)
		shell_env();
	else if (_strcmp(av[0], "setenv") == 0)
		_setenv(av[1], av[2]);
	/* cmd_status = (_setenv(av[1], av[2]) ? 2 : 0);*/
	/* _setenv(char *variable, char *value);*/
	else if (_strcmp(av[0], "unsetenv") == 0)
		/* cmd_status = (_unsetenv(av[1]) ? 2 : 0);*/
		_unsetenv(av[1]);
	/* else if (_strcmp(av[0], "cd") == 0)*/
	/*cmd_status = change_dir(av[1]);*/
	/*else if (_strcmp(av[0], "alias") == 0)*/
	/*cmd_status = alias(av);*/
	else
		success = 0;
	return (success);
}


/**
 * run_sys_cmd - runs a command and waits for it to finish
 *
 * @av: array of strings storing the command and it's arguments
 * @n: number of arguments in av
 * @argv: program argument vector
 * Return: exit status code of child process
 */
int run_sys_cmd(char **av, int n __attribute__((unused)), char **argv)
{
	char *prog_path;
	int child_pid, child_status = -1;
	/*struct stat st;*/

	prog_path = parse_path(av[0]);
	if (prog_path == NULL)
	{
		perror(*(argv + 0));
		return (-1); /* failure or error condition in the code */
	}
	child_pid = fork();
	if (child_pid == -1)
		perror(*(argv + 0));
	if (child_pid == 0)
	{
		if (execve(prog_path, av, environ) == -1)
		{
			perror(*(argv + 0));
			free_array(av);
			free_pointer(prog_path, NULL);
			_exit(1);
		}
	}
	else if (child_pid > 0)
		wait(&child_status);
	/*free(prog_path);*/
	free_pointer(prog_path, NULL);
	return (child_status / 256);
}
