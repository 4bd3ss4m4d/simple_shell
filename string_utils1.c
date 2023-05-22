#include "simple_shell.h"

/**
 * _strcpy - Copie Source To Destination Char
 * @dest: Destination
 * @src: Source
 *
 * Return: Copie Of Char *
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concat Two String
 * @dest: First String
 * @src: Second String
 *
 * Return: First String + Second String Char *
 */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}

/**
 * _strchr - Locate Charactere In String
 * @str: String Search In
 * @c: Char To Search For
 *
 * Return: Pointer To Char*
 */

char *_strchr(char *str, char c)
{

	do {

		if (*str == c)
			break;
	} while (*str++);

	return (str);
}

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @str1: A String.
 * @str2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}
	return (0);
}

/**
 * _strdup - Duplicate A String
 * @str: String
 *
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);

	for (i = 0; i <= len; i++)
		str2[i] = str[i];

	return (str2);
}
