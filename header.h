#ifndef HEADER_H
#define HEADER_H

/* standar libraries */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>



#define UNUSED __attribute__((unused))
#define MAX_ARGS_COUNT 1000
#define MAX_ARG_LEN 1000
#define PATH_MAX 4096

#define BUFFER_SIZE 100


/*extern char **environ;*/



/* functions prototypes */
void create_abs_path(char *directory, char *filename, char *absolute_path);
char *_exec_file(char *path);
int run_built_in_command(char **av, char *line_buffer, char **envp);

void shell_prompt(void);
void run_cmd(char *line_buffer, char **argv, char **envp);
int run_sys_cmd(char **av, char **argv, char **envp);
void sig_handler(int sig);


/* error */
/*void error_file(char *file);*/


/* build-in commands */
void shell_exit(char **av);
void shell_env(char **envp);
int _unsetenv(char *variable, char **envp);
int _setenv(char *variable, char *value, char **envp);
char *format_tilde(char *str, char **envp);
int change_dir(char *dir, char **envp);
int alias(char **tokens, char **envp);
/* end */

/* parser functions */
int parse_cmd(char *cmd, char **argv);
char *parse_path(char *cmd);
void split_cmds(char *buffer, UNUSED char *separator, char **cmd, char **rest);

/* changed functions */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _strtok(char *str, char *delim, char **save);
/* end */


/* utils functions */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *s);
char *_strchr(char *str, int ch);
char *_substr(char *src, int m, int n);
int _atoi(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_get_env(char *arg, char **envp);
int _is_env_variable(char *name, char **envp);
int _get_env_len(char **envp);
void _format(char *str1, char *str2, char *save, char *delim);
int process_file(char *file, int *fd);
int setup_env(char **envp);
/* end*/

int print_alias(char *name, char **envp);
int set_alias(char *new_value, char **envp);


/* deallocate memory functions */
void free_env(char **envp);
void free_pointer(char *str, ...);
void free_array(char **av);

/* end */


/* printf handler */
void print_str(char *str);
void print_error(char *str);
void _print(char *str, int fd);


/* memory helper */
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(char *ptr, size_t old_size, size_t new_size);


#endif
