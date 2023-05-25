#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

extern char **environ;
extern int status_code;

/* prompt.c */
void prompt(void);

/* get_input.c */
char *get_input(void);
void free_last_input(void);
/* get_line.c*/
void *get_line(void);

/* built-in funcs */
int check_for_builtin(char **args);
int execute_buitlin(char *cmd, char **args);
void _help(void);
void shell_exit(char **args);
void _cd(char **args);
int _setenv(char **args);
int _unsetenv(char **args);
int _env(void);
int _clear(char **args);

/* signal_handler.c */
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);

/* execute.c */
int execute(char **args);

/* parser.c */
char **_tokenize(char *str, const char *delim);
char **tokenize_input(char *input);

/* _env.c */
/*char *_getenv(const char *name);*/
char *_get_env(char *arg);
int _get_env_len(void);
int _is_env_variable(char *var_name);

/* get_path.c */
char *get_path(void);

/* find_in_path.c */
char *find_in_path(char *command);

/* free.c */
void free_error(char **argv, char *arg);
void free_double_pointer(char **ptr);
void free_environ(void);

/* error.c */
void _puts(char *str);
void _puterror(char *err);

/* utils_funcs1.c */
int _strlen(const char *);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *s, char c);

/* utils_funcs2.c */
char *_strcpy(char *, char *);
char *_strcat(char *, const char *);
char *_strdup(const char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);

/* utils_funcs3.c */
int _atoi(const char *str);
char *_itoa(int num);
char *_memset(char *, char, unsigned int);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int nmemb, unsigned int size);

/* printf utils functions */
int _write(char *str, int fd);
int _write_stdout(char *str);
int _write_stderr(char *str);

/* useful helper functions */
void create_abs_path(char *directory, char *filename, char *absolute_path);
int is_numeric(char *s);
int digits(int num);
int is_digit(char c);

#endif
