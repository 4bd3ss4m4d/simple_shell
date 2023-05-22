#include "simple_shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncpy - copie a string
 * @dest: char
 * @src: char
 * @n: int
 *
 * Return: char
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @str: char
 *
 * Return:int
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _atoi - convert to a int
 * @str: string
 *
 * Return: int
 */
int _atoi(char *str)
{
	int i, j, k, l;

	i = k = 0;
	l = 1;
	while ((str[i] < '0' || str[i] > '9') && (str[i] != '\0'))
	{
		if (str[i] == '-')
			l *= -1;
		i++;
	}
	j = i;
	while ((str[j] >= '0') && (str[j] <= '9'))
	{
		k = (k * 10) + l * ((str[j]) - '0');
		j++;
	}
	return (k);
}

/**
 * _puts - print a string
 * @str: pointer char
 *
 * return: void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

