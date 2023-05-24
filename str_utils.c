#include "header.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	if (dest == NULL || src == NULL)
		return (NULL);
	/* get the length of dest */
	i = _strlen(dest), j = 0;

	/* add src to the end of dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}




/**
 *_strlen -  a function that returns the length of a string.
 *@s: the string to return
 *Return:None
 */


int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}



/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	if (dest == NULL || src == NULL)
		return (NULL);
	len = _strlen(src);
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strdup - returns a pointer to a copy of a string
 *
 * @s: string to be copied
 *
 * Return: pointer to new copy
 */
char *_strdup(char *s)
{
	char *copy = NULL;
	size_t len = 0, i;

	if (s == NULL)
		return (NULL);

	len = _strlen(s) + 1;

	copy = malloc(len * sizeof(char));

	if (copy != NULL)
	{
		for (i = 0; i < len; i++)
			copy[i] = s[i];
		/* Null-terminate the string */
		copy[len] = '\0';
	}

	return (copy);
}

/**
 * _strchr - finds first instance of a char
 *				in a string.
 *
 * @str: the string to search in.
 * @ch: the character to search for.
 *
 * Return: If found, return a pointer value,
 *				If not, return NULL.
 */
char *_strchr(char *str, int ch)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (ch == str[i])
			return (&str[i]);
	}

	return (NULL);
}
