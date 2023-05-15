#ifndef SHELL_H
#define SHELL_H

/* standar libraries */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void display_prompt(void);
void run_program(char **exec_path, int *status, char **av);
void exec_program(char *exec_path, char *av);
void _strtok(char *str, char *delim, char **save);


/* utils function */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
