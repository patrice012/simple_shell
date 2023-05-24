#include "header.h"

/**
  * create_absolute_path - create an absolute path
  * @directory: path to the directory
  * @filename: filename
  * @absolute_path: the output path
  */

void create_absolute_path(char *directory, char *filename, char *absolute_path)
{
	_format(directory, filename, absolute_path, "/");
}


/**
  * _format - format the string output base on the delimeter
  * @save_char: string to hold the result
  * @first_char: 1rst string to add
  * @second_char: 2nd string to concatenate
  * @delim: delimiter to use
  */

void _format(char *first_char, char *second_char, char *save_char, char *delim)
{
	_strcpy(save_char, first_char);
	_strcat(save_char, delim);
	_strcat(save_char, second_char);
	_strcat(save_char, "\0");
}


/**
 * free_pointer - free all pointers
 * @ptr: first pointer to free
 * @...: variable arguments, terminated by a NULL pointer
 * the last argument should be NULL - Mandatory
 * Return: 0 if success and -1 if fail
 */


void free_pointer(char *ptr, ...)
{
	va_list arg;
	char *temp;

	if (ptr == NULL)
		return;

	va_start(arg, ptr);

	temp = ptr;

	while (temp != NULL)
	{
		free(temp);
		temp = va_arg(arg, char *);
	}
	temp = NULL;
	va_end(arg);
}


/**
 * free_array - free all elements in array
 * @av: array to free
 * Return: void
 */

void free_array(char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
