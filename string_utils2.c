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

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = int_length(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 *  array_rev - Reverse Array
 * @arr: Array To Reverse
 * @len: Length Of Array
 *
 * Return: Void(Reverse Array)
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * int_length - Determine Length Of Int
 * @n: Given Int
 *
 * Return: Length Of Int
 */
int int_length(int n)
{
	int len = 0;

	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

