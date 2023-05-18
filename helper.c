#include "header.h"

/**
  * build_abs_path - create an absolute path
  * @directory: path to the directory
  * @filename: filename
  * @absolute_path: the output path
  */

void build_abs_path(char *directory, char *filename, char *absolute_path)
{
    _strcpy(absolute_path, directory);
    _strcat(absolute_path, "/");
    _strcat(absolute_path, filename);
}


/**
 * clean_up - free all pointers
 * @str: pointer of string
 * Return: 0 if success and -1 if fail
 */


