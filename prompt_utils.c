#include "simple_shell.h"

/**
 * display_prompt - prints shell prompt
 */
void display_prompt(void)
{
	PRINTER("$ ");
}

/**
 * print_num -prints an int that is unsigned
 * @n: the unsigned integer
 *
 * Return: Void
 */
void print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_num_pch - prints number to the terminal using _putchar()
 * @n: Integer
 *
 * Return: void
 */
void print_num_pch(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}
