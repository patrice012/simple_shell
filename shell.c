#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void display_prompt(void);
void run_program(char **exec_path, int *status, char **av);
void exec_program(char *exec_path, char *av);
void _strtok(char *str, char *delim, char **save);

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



/**
  * _strtok - breaks a string into a sequence of zero or more nonempty tokens
  * @str: string to break
  * @delim: delimiter to use
  * @save: array to save strings in
  * Return: None
  */

void _strtok(char *str, char *delim, char **save)
{
	/* set i==1 because argv[0] should be the path of the program */
	int i = 0;
	char *_str = strtok(str, delim);

	while (_str != NULL)
	{
		/* add to save array == argv */
		*(save + i) = _str;
		/* call again strtok for the next string */
		_str = strtok(NULL, delim);
		i++;
	}
	/* set environment variable to NULL */
	*(save + i) = NULL;
	return;
}
