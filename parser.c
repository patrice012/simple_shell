#include "header.h"

/**
 * _tokenize - parsing user input into arguments
 *            by splits an array string into tokens using a delimiter.
 * @str: the string to be tokenized.
 * @delim: the delimiter used to split the string.
 *
 * Return: an array of pointers to the tokens,
 *         or NULL if an error occurs.
 */
char **_tokenize(char *str, const char *delim)
{
	char *token = NULL;
	char **result_array = NULL;
	int i = 0;

	if (!str || !delim)
		return (NULL);

	token = strtok(str, delim);
	while (token)
	{
		result_array = realloc(result_array, sizeof(char *) * (i + 1));
		if (result_array == NULL)
			return (NULL);

		result_array[i] = malloc(sizeof(char *) * _strlen(token) + 1);
		if (result_array[i] == NULL)
			return (NULL);

		_strcpy(result_array[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	/*increase the size of the array*/
	result_array = realloc(result_array, (i + 1) * sizeof(char *));
	if (!result_array)
		return (NULL);

	result_array[i] = NULL;
	return (result_array);
}

/**
 * tokenize_input - splits a user input string into tokens with tokenize().
 * @input: the user input string to be tokenized
 *
 * Return: an array of pointers to the tokens, or NULL if an error occurs
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *temp = NULL, *delim = " \t\r\n\a";

	temp = _strdup(input);
	if (temp == NULL)
	{
		_puts("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	tokens = _tokenize(temp, delim);
	free(temp);

	return (tokens);
}
