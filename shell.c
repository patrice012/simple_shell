#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void display_prompt(void);
void run_program(char **exec_path, int *status);
void exec_program(char *exec_path);

/**
 * main - main function
 * Return: always 0
 */



int main(void)
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
		run_program(&line, &status);
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

/**
  * run_program - run a program base on the argument
  * @exec_path: path to the executable file
  * @status: type of interger, allow to control parent process running
  * Return: Nothing
  */

void run_program(char **exec_path, int *status)
{
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
		exec_program(*exec_path);
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
  */


void exec_program(char *path)
{
	char *envp[] = { NULL };
	char *argv[] = {path, NULL};
	int i = execve(path, argv, envp);

	if (i == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
