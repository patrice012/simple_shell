#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to append to
 * @src: string to add
 *
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	if (dest == NULL || src == NULL)
		return (NULL);

	/* get the length of dest */
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
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
	if (s == NULL)
		return (-1);

	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
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
	if (dest == NULL || src == NULL)
		return (NULL);

	int len, i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

