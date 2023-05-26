 #include "main.h"


/**
 * check_for_builtin - checks if the command is a builtin
 * @argv: the arguments array
 * @line_buffer: user input
 * Return: 0 if command is a builtin, 1 otherwise
 */
int check_for_builtin(char **argv, char *line_buffer)
{
	int cmd_status;

	if (!argv[0])
		return (0);
	if (_strcmp(argv[0], "exit") == 0)
		cmd_status = exit_shell(line_buffer, argv);
	else if (_strcmp(argv[0], "env") == 0)
		_env();
	else if (_strcmp(argv[0], "setenv") == 0)
		cmd_status = (_setenv(argv[1], argv[2]) ? 2 : 0);
	else if (_strcmp(argv[0], "unsetenv") == 0)
		cmd_status = (_unsetenv(argv[1]) ? 2 : 0);
	else if (_strcmp(argv[0], "cd") == 0)
		cmd_status = change_directory(argv[1]);
	else if (_strcmp(argv[0], "alias") == 0)
		cmd_status = alias(argv);
	else if (_strcmp(argv[0], "help") == 0)
		cmd_status = _help();
	else
		return (1);
	return (cmd_status);
}
