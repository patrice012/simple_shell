#include "shell.h"

void display_prompt();

/**
 * main - main function
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * Return: always 0
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int status;

	while (1)
	{
		display_prompt();
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		line[read - 1] = '\0';
		run_program(&line, &status, argv);
	}
}


/**
  * display_prompt - display the prompt to user
  * Return: Nothing
  */

void display_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}
