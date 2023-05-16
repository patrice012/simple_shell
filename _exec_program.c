#include "header.h"


/**
  * run_program - run a program base on the argument
  * @exec_path: path to the executable file
  * @status: type of interger, allow to control parent process running
  * @av: vector of arguments fill to main
  * Return: Nothing
  */

void run_program(char **user_input, int *status, char **av)
{
	const char *command;
	char *abs_path, *input_array[MAX_ARGUMENTS + 1];

	/* split user input and get the first element == command */
	_strtok(*user_input, " ", input_array);
	command = input_array[0];
	/* find exec file */
	int found = check_command_existence(command, &abs_path);

	if (!found)
	{
		printf("%s command not found\n", input_array[0]);
		return;
	}

	/* create pid */
	pid_t child_pid;
	/* fork new process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		exec_program(abs_path, input_array, *av);
	}
	else
	{
		/* suspence parent process unti all child process finished*/
		wait(status);
	}
}



/**
  * exec_program - execute the given program
  * @path: path to the executable file
  * @av: copy of vector arguments passed to main file
  */


void exec_program(char *abs_path, char **args, char *av)
{
	int i;
	char *envp[] = { NULL };
	/*char **argv = args;*/

	/* execute the program with all provider arguments */
	i = execve(abs_path, args, envp);

	if (i == -1)
	{
		perror((av + 0));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int check_command_existence(const char *command, char **executablePath)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL) {
		snprintf(*executablePath, MAX_PATH_LENGTH, "%s/%s", token, command);
		/*build_abs_path(token, command, executablePath);*/
		if (access(*executablePath, X_OK) == 0) {
			return 1;
		}
		token = strtok(NULL, ":");
	}
	return 0;
}
