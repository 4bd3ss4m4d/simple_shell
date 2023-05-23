#include "simple_shell.h"

/**
 * read_file - Read Command From File
 * @file: Name of the file to read commands from.
 * @argv: Name of the program.
 *
 * Return: Void.
 */
void read_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * treat_file - Process and Execute Commands from a File Line
 * @file_line: Line from the file containing a command.
 * @counter: Error counter to track the number of errors encountered.
 * @fp: File pointer to the opened file.
 * @argv: Name of the program.
 *
 * Return: Void.
 */
void treat_file(char *file_line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_command(file_line);

	if (_strncmp(cmd[0], "exit", 4) == 0)
	{
		exit_file(cmd, file_line, fp);
	}
	else if (check_bltn(cmd) == 0)
	{
		st = handle_builtin(cmd, st);
		free(cmd);
	}
	else
	{
		st = check_cmd(cmd, file_line, counter, argv);
		free(cmd);
	}
}

/**
 * exit_file - Exit the Shell when Executing a Command from a File
 * @command: Parsed command arguments
 * @file_line: Line from the file containing the command
 * @fd: File pointer
 *
 * Return: Void.
 */
void exit_file(char **command, char *file_line, FILE *fd)
{
	int statue, i = 0;

	if (command[1] == NULL)
	{
		free(file_line);
		free(command);
		fclose(fd);
		exit(errno);
	}
	while (command[1][i])
	{
		if (_isalpha(command[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(command[1]);
	free(file_line);
	free(command);
	fclose(fd);
	exit(statue);
}
