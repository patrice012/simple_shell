#include "header.h"




/**
 * _atoi - convert string to integer
 * @str: string
 * Return: returns integer.
 * note: *10 is an indication if digit.
 */
int _atoi(char *str)
{
    int res = 0, sign = 1;
    int i = 0;

    while (str[i] == ' ')
        i++;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return (sign * res);
}


