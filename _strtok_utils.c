#include "simple_shell.h"

/**
 * check_delimiter - Checks the delimiter
 * @c: the command to check
 * @str: pointer to the string
 *
 * Return: 1 on Success or 1 on failure
 */
unsigned int check_delimiter(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Tokenize a string
 * @str: pointer to the string
 * @delimiter: the delimiter charcter
 *
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delimiter)
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delimiter(ts[i], delimiter) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delimiter(nt[i], delimiter) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}

	return (ts);
}

