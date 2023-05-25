#include "header.h"

/**
 * main - implements a simple shell
 *
 * Return: EXIT_SUCCESS.
 */
int main(void)
{
	char *input;
	char **args;
	int status, fd = STDIN_FILENO;

	/* Register signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		/* print shell prompt in interactive mode */
		if (isatty(fd))
			prompt();
		input = get_input();
		if (!input || !*input)/* EOF detected, exit the loop */
			break;

		args = tokenize_input(input);
		if (!args || !*args)
		{
			free(input);
			free_double_pointer(args);
			continue;
		}
		status = execute(args);
		free(input);
		free_double_pointer(args);
		if (!isatty(fd))
			break;
		/* Set status to 1 to continue the loop */
		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
