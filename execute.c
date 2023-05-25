#include "header.h"


/**
 * create_process - fork new process
 * Return: process id
 */

pid_t create_process(void)
{
	pid_t id;

	id = fork();
	if (id < 0)
	{
		_puterror("fork");
		return (1);
	}
	return (id);
}

/**
 * execute_system_cmd - execute system command
 * @argv: program arguments
 */

void execute_system_cmd(char **argv)
{
	char *envp[2], *cmd_path;

	envp[0] = get_path();
	envp[1] = NULL;
	cmd_path = NULL;
	if (argv[0][0] != '/')
		cmd_path = find_in_path(argv[0]);
	if (cmd_path == NULL)
		cmd_path = argv[0];
	if (execve(cmd_path, argv, envp) == -1)
	{
		perror(argv[0]), free_double_pointer(argv);
		free_last_input();
		exit(EXIT_FAILURE);
	}
}

/**
 * execute - Execute a command with arguments.
 * @argv: An array of strings containing the command and its arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute(char **argv)
{
	pid_t id;
	int status = 0;

	if (argv == NULL || *argv == NULL)
		return (status);
	if (check_for_builtin(argv))
		return (status);

	id = create_process();
	if (id == -1)
	{
		perror(argv[0]), free_double_pointer(argv);
		free_last_input();
	}
	if (id == 0)
		execute_system_cmd(argv);
	else
	{
		do {
			waitpid(id, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (status);
}
