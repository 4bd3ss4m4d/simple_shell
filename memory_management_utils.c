#include "simple_shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block
 * @old_s: Previous size of the memory block
 * @new_s: New size of the memory block
 *
 * Return: Void pointer to the reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	void *result;

	if (new_s == old_s)
		return (ptr);
	if (new_s == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_s);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_s);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_s);
		free(ptr);
	}
	return (result);
}
/**
 * free_all - Free array of char pointer and char pointer
 * @command: Pointer to the array of char pointers
 * @command_line: Pointer to the char pointer
 *
 * Return: Void
 */
void free_all(char **command, char *command_line)
{
	free(command);
	free(command_line);
	command = NULL;
	command_line = NULL;
}

/**
 * _memcpy - Copy a specified number of bytes from source to destination
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source buffer
 * @n: Number of bytes to copy
 *
 * Return: Void Pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * fill_an_array - Fill an array with a constant byte
 * @a: Pointer to the array
 * @el: Integer value to fill the array with
 * @len: Length of the array
 *
 * Return: Pointer to the filled array
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}

	return (a);
}

/**
 * _calloc - Allocates memory for an array, using malloc.
 * @size: Size of the array
 *
 * Return: Void pointer to the allocated memory
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
		return (NULL);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		a[i] = '\0';

	return (a);
}

