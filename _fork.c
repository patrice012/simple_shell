#include "header.h"


/**
 * create_process - fork new process
 * Return: process id
 */

int create_process(void)
{
	int child_pid;

	child_pid = fork();
	if (child_pid == -1)
		perror(prog_name);
	return (child_pid);
}

