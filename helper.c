#include "header.h"

/**
  * build_absolute_path - create an absolute path
  * @directory: path to the directory
  * @filename: filename
  * @absolute_path: the output path
  */

void build_absolute_path(char *directory, char *filename, char *absolute_path)
{
    _strcpy(absolute_path, directory);
    _strcat(absolute_path, "/");
    _strcat(absolute_path, filename);
    _strcat(absolute_path, "\0");
}


/**
 * free_pointer - free all pointers
 * @ptr: first pointer to free
 * @...: variable arguments, terminated by a NULL pointer
 * the last argument should be NULL
 * Return: 0 if success and -1 if fail
 */


/*
 * Usage: free_pointer(ptr1; ptr2, ptr3, NULL);
 */

void free_pointer(char *ptr, ...)
{
    va_list arg;
    va_start(arg, ptr);

    char *temp = ptr;
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




