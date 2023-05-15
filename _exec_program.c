#include "shell.h"


/**
  * run_program - run a program base on the argument
  * @exec_path: path to the executable file
  * @status: type of interger, allow to control parent process running
  * @av: vector of arguments fill to main
  * Return: Nothing
  */

void run_program(char **exec_path, int *status, char **av)
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
		exec_program(*exec_path, *av);
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


void exec_program(char *path, char *av)
{
	int i;
	char *envp[] = { NULL }, *delim = " ";
	char *argv[] = {};

	/* split and save path to argv */
	_strtok(path, delim, argv);
	/* execute the program with all provider arguments */
	i = execve(path, argv, envp);

	if (i == -1)
	{
		perror((av + 0));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


