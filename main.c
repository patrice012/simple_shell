#include "main.h"

char *prog_name;
int status_code;
int hist;

void sig_handler(int sig);
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
