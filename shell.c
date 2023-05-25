#include "header.h"

void sig_handler(int sig);

int status_code;
char *program_name;

/**
 * main - main function
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * Return: always 0
 */

int main(int argc, char **argv)
{
	char *line_buffer = NULL;
	size_t len = 0;
	ssize_t read;
	int fd = STDIN_FILENO; /* set status */

	signal(SIGINT, sig_handler);
	program_name = argv[0];

	if (argc > 1)
	{
		status_code = process_file(argv[1], &fd);
		if (status_code)
			return (status_code);
	}

	(void)argv;
	(void)argc;
	if (setup_env() == -1)
	{
		free_env();
		return (-1);
	}

	while (1)
	{
		/*  shell work in interactive mode ? print prompt */
		if (isatty(fd))
			shell_prompt();
		/* read user input into line_buffer */
		read = _getline(&line_buffer, &len, stdin);
		printf("buffer: %s read:%ld\n", line_buffer, read);
		if (read == -1)
			break;
		/* check if the first character is not Null-terminate */
		/*if (line_buffer[0] != '\0')*/
			/* run cmd */
		run_cmd(line_buffer, argv);
		if (!isatty(fd)) /* non-interactive */
			break;
	}
		if (fd != STDIN_FILENO)
			close(fd);

		if (isatty(fd))
			print_str("\n");

	/* cleaning the environment and all pointers */
	free_env();
	free(line_buffer);
	program_name = NULL;
	return (status_code);
}


/**
  * shell_prompt - display the prompt to user
  * Return: Nothing
  */

void shell_prompt(void)
{
	char cwd[PATH_MAX], *format;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");

	format = format_tilde(cwd);
	if (format != NULL)
		_strcpy(cwd, format);
	print_str(cwd);
	free(format);
	print_str("$ ");
	fflush(stdout);
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
