#include "header.h"

void shell_prompt(void);

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
	int status, fd = STDIN_FILENO;

	while (1)
	{
		/*  shell work in interactive mode ? print prompt */
		if (isatty(fd))
			shell_prompt();
		/* read user input into line_buffer */
		read = getline(&line_buffer, &len, stdin);
		if (read == -1)
			break;
		line_buffer[read - 1] = '\0';
		/* run cmd */
		run_cmd(line_buffer, argv);
	}
}


/**
  * display_prompt - display the prompt to user
  * Return: Nothing
  */

void shell_prompt(void)
{
	print_str("$ ");
	fflush(stdout);
}
