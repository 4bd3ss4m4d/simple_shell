#include "simple_shell.h"

/**
 * _strcmp - Compare Two String
 * @str1 :String 1
 * @str2: String 2
 *
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp(char *str1, char *str2)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			cmp = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Check if Alphabtic
 *@c: Character
 *
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
