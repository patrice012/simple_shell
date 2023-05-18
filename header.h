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
#include <sys/stat.h>

/* macros */

/*
 * #define MAX_TOKENS 50
 * #define MAX_COMMAND_LENGTH 100
 * #define MAX_PATH_LENGTH 1024
 * #define MAX_ARGUMENTS 10
 * #define MAX_FILENAME_LEN 256
 */

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MAX_ARGS_COUNT 1000
#define MAX_ARG_LEN 1000
#define PATH_MAX 4096


extern char **environ;


/* functions prototypes */

void build_absolute_path(char *directory, char *filename, char *absolute_path);
char *_exec_file(char *path);
int run_built_in_command(char **argv, char *line_buffer);

void shell_prompt(void);
void run_cmd(char *line_buffer, char **argv);
int run_sys_cmd(char **argv, int n, char **av);
void sig_handler(int sig);




/* build-in commands */
void shell_exit(void);
void shell_env(void);
/* end */

/* parser function */
int parse_cmd(char *cmd, char **argv);
char *parse_path(char *cmd);
void _strtok(char *str, char *delim, char **save);
/* end */


/* utils function */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strchr(char *str, int ch);
int _atoi(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_get_env(char *arg);
void free_env(void);
// int clean_up(char *str, ...);

/* end */


/* printf handler */
void print_str(char *str);
void print_error(char *str);
void _print(char *str, int fd);


#endif
