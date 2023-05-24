#include "header.h"

void sig_handler(int sig);

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

	if (argc > 1 || argv == NULL)
	{
		print_error("Please run with no arguments\n");
		exit(127);
	}

	signal(SIGINT, sig_handler);

	while (1)
	{
		/*  shell work in interactive mode ? print prompt */
		if (isatty(fd))
			shell_prompt();
		/* read user input into line_buffer */
		read = getline(&line_buffer, &len, stdin);
		if (read == -1)
			break;
		/* check if the first character is not Null-terminate */
		if (line_buffer[0] != '\0')
			/* run cmd */
			run_cmd(line_buffer, argv);
	}

		if (isatty(fd))
			print_str("\n");

	/* cleaning the environment and all pointers */
	free_env();
	free_pointer(line_buffer, NULL);
	free_array(argv);
	return (0);
}


/**
  * shell_prompt - display the prompt to user
  * Return: Nothing
  */

void shell_prompt(void)
{
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
