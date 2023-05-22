#include "simple_shell.h"

/**
 * main - Entry Point (Shell)
 * @argc: Argument Count
 * @argv:Argument Value
 *
 * Return: Exit Value By Status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	int counter = 0, statue = 1, st = 0;
	char *inp, **command;

	if (argv[1] != NULL)
		read_file(argv[1], argv);

	signal(SIGINT, signal_to_handel);

	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			display_prompt();
		inp = _getline();
		if (inp[0] == '\0')
			continue;
		history(inp);
		command = parse_command(inp);
		if (_strcmp(command[0], "exit") == 0)
			exit_status_shell(command, inp, argv, counter);
		else if (check_bltn(command) == 0)
		{
			st = handle_builtin(command, st);
			free_all(command, inp);
			continue;
		}
		else
			st = check_cmd(command, inp, counter, argv);
		free_all(command, inp);
	}

	return (statue);
}
