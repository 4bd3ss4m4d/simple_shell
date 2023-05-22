#include "simple_shell.h"

/**
 * print_err - prints error to the terminal
 * @input: the command typed by the user
 * @counter: Counter
 * @argv: argument vector
 *
 * Return: Void
 */
void print_err(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}

/**
 *  _prerror - prints a custom error to the terminal
 * @argv: Arguments vector
 * @c: Number of errors
 * @cmd: pointer to the pointer that contains the command
 *
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(er);
}
