#include "header.h"

/**
 * free_double_pointer - frees memory allocated dynamically by tokenize()
 * @ptr: pointer to allocated memory
 *
 * Return: void.
 */
void free_double_pointer(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
		free((ptr[i]));
}



/**
 * free_env - frees the memory that the environment copy
 *                                                takes.
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		free(environ[i]);
	free(environ);
}
