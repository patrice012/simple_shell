#ifndef _SHELL_H_
#define _SHELL_H_

void display_prompt(void);
void run_program(char **exec_path, int *status, char **av);
void exec_program(char *exec_path, char *av);
void _strtok(char *str, char *delim, char **save);


/* utils function */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
