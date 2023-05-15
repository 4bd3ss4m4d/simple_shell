#include <errno.h>
#include "simple_shell.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
	char *command = NULL;
	size_t len_command = 0;
	ssize_t nchars_command;

	signal(SIGINT, sigint_handler);

	/* Loop forever */
	while (true)
	{
		/* Display prompt */
		bool prompt_displayed = display_prompt();

		if (!prompt_displayed)
		{
			return (EXIT_FAILURE);
		}

		/* Read command */
		nchars_command = getline(&command, &len_command, stdin);

		/* Handle End-Of-File EOF (CTRL + D) */
		if (nchars_command == EOF)
		{
			if (eof_handler(command) == 0)
			{
				exit(EXIT_SUCCESS);
			}
		}

		/* Free memory for command and set length of command to 0 */
		free(command), len_command = 0;
	}
}

bool display_prompt(void)
{
	FILE *fp = stdin;
	char *prompt_text = "$ ";
	int nbytes = _strlen(prompt_text);

	/* Check if standard input is a terminal and if the file
	pointer is equal to standard input */
	if (isatty(STDIN_FILENO) && fp == stdin)
	{
		if (write(STDOUT_FILENO, prompt_text, nbytes) == -1)
		{
			return (false);
		}
	}
	/* If file is not a terminal */
	else
	{
		return (false);
	}

	return (true);
}

int eof_handler(char *commandptr)
{
	char new_line[] = {'\n', '\0'};
	int nbytes = _strlen(new_line);

	if (commandptr == NULL)
	{
		return (1);
	}
	else
	{
		free(commandptr);
		commandptr = NULL;
		if (write(STDOUT_FILENO, new_line, nbytes) == -1)
		{
			return (-1);
		}
	}

	return (0);
}

void sigint_handler(int signum __attribute__((unused)))
{
	char new_line[] = {'\n', '\0'};
	int nbytes = _strlen(new_line);
	write(STDOUT_FILENO, new_line, nbytes);
	display_prompt();
}
