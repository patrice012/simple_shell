#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define UNUSED __attribute__((unused))
#define MAX_ARGS_COUNT 1000
#define MAX_ARG_LEN 1000
#define PATH_MAX 4096

extern char **environ;
extern char *prog_name;
extern int status_code;
extern int hist;

/* Parsers */
int parse_cmd(char *cmd, char **argv);
char *find_in_path(char *cmd);
void split_cmd(char *buffer, char *separator, char **cmd, char **rest);

/* Built-in shell functions */
int exit_shell(char *line_buffer, char **argv);
void _env(void);
char *format_cmd_line(char *str);
int change_directory(char *dir);
int alias(char **tokens);


int _help(void);
int _clear(void);


/* command utils */
void shell_prompt(void);
void execute(char *line_buffer);
int execute_system_cmd(char **argv, int n);
int create_process(void);
int check_for_builtin(char **argv, char *line_buffer);


/* signal handler utils */
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);


/* string functions */
size_t _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *str, int ch);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
char *_substr(char *src, int m, int n);
int _atoi(char *str);
char *_itoa(int num);
int is_numeric(char *s);
int is_digit(char c);

/* getline functions */
int _getline(char **lineptr, size_t *n, int stream);
ssize_t get_input(char **buffer, int fd);

/* environment functions */
int setup_env(void);
int _get_env_len(void);
void free_env(void);
char *_get_env(char *var);
int _setenv(char *name, char *value);
int _unsetenv(char *name);

/* memory functions */
void _memcpy(void *dest, void *src, size_t n);
void *_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size);
void *_memchr(char *s, char c, int n);
void *_calloc(size_t count, size_t size);
void *_recalloc(void *ptr, unsigned int old_size,
		unsigned int new_size);

/* print functions */
void print_str(char *s);
void print_err(char *s);

/* shell handlers */
void handle_variables(char **argv);
void handle_aliases(char **argv);

/* error handling */
void error_127(char *cmd);
void error_126(char *cmd);
void error_exit(char *value);
void error_cd(char *dir);
void error_file(char *file);

/* File processing */
/*int check_file(char *file, int *fd);*/

/* write utils */
int _write_stdout(char *str);
int _write_stderr(char *str);
int _putchar(char c);


/* helper functions */
void free_double_pointer(char **ptr);

/* alias utils */
int print_alias(char *name);
int set_alias(char *new_value);


#endif
