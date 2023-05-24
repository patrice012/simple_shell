#include "header.h"

/**
  * _strtok - breaks a string into a sequence of zero or more nonempty tokens
  * @str: string to break
  * @delim: delimiter to use
  * @save: array to save strings in
  * Return: None
  */

void _strtok(char *str, char *delim, char **save)
{
	/* set i==0 because argv[0] should be the path of the program */
	int i = 0;
	char *_str = strtok(str, delim);

	while (_str != NULL && i < MAX_ARGS_COUNT)
	{
		/* add to save array == argv */
		*(save + i) = _str;
		/* call again strtok for the next string */
		_str = strtok(NULL, delim);
		i++;
	}
	/* set environment variable to NULL */
	*(save + i) = NULL;
}


