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

/**
 * print_ech - runs the echo command
 * @command: pointer to the pointer that contains the command
 *
 * Return: 0 Success or -1 if it fails
 */
int print_ech(char **command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", command, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * disp_hist - Displays history to the terminal
 * @c: the pointer to the pointer that contains the command
 * @s: The status number
 *
 * Return: 0 Success or -1 if it fails
 */
int disp_hist(__attribute__((unused)) char **c, __attribute__((unused)) int s)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

