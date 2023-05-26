#include "main.h"

char *prog_name;
int status_code;
int hist;

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument list
 * @envp: environment variable list
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp __attribute__((unused)))
{
	/*size_t line_size = 0;*/
	int fd = STDIN_FILENO;
	char *line_buffer = NULL;

	prog_name = argv[0];
	signal(SIGINT, sig_handler);
	/*
	 *if (argc > 1)
	 *{
	 *	status_code = process_file(argv[1], &fd);
	 *	if (status_code)
	 *		return (status_code);
	 *}
	 */
	if (setup_env())
		return (-1);

	(void)argv;
	(void)argc;

	while (1)
	{
		if (isatty(fd))
			shell_prompt();
		if (get_input(&line_buffer, fd) != -1)
			execute(line_buffer);
		else
			break;
	}
	free_env();
	free(line_buffer);
	if (fd != STDIN_FILENO)
		close(fd);
	if (isatty(fd))
		print_str("\n");
	return (status_code);
}


/**
 * execute - checks whether a command is built-in or system command and
 * calls the relevant function
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void execute(char *line_buffer)
{
	int n, j, cmd_status;
	char *argv[MAX_ARGS_COUNT + 1], *cmd;/* *rest, sep*/

	/*rest = line_buffer;*/
	cmd = line_buffer;/* cmd => rest */
	while (cmd != NULL)/* cmd => rest */
	{
		/*split_cmd(rest, &sep, &cmd, &rest);*/
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
		/*if (sep == '|' && cmd_status == 0)*/
			/*break;*/
		/*else if (sep == '&' && cmd_status != 0)*/
			/*break;*/
		/*else if (sep == '#')*/
			/*break;*/
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

/**
 * sig_handler - handle SIGINT signal
 *
 * @sig: signal value
 */
void sig_handler(int sig)
{
	print_str("\n");
	shell_prompt();
	(void) sig;
}
