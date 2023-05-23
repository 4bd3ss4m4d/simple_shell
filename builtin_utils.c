#include "simple_shell.h"

/**
 * exit_status_shell - Exit Shell with Status
 * @cmd: Parsed command
 * @input: User input
 * @argv: Program name
 * @c: Execution count
 *
 * Return: Void (Exit status).
 */
void exit_status_shell(char **cmd, char *input, char **argv, int c)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			statue = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(statue);
		}
	}
}

/**
 * change_dir - Change Directory
 * @command: Parsed command
 * @er: Status of the last command executed
 *
 * Return: 1 On Success 0 on Failure
 */
int change_dir(char **command, __attribute__((unused)) int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(command[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * dis_env - Display Environment Variables
 * @cmd: Parsed command
 * @er: Status of the last command executed
 *
 * Return: Always 0.
 */
int dis_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * display_help - Display Help for Builtin
 * @command: Parsed command
 * @status: Status of the last command executed
 *
 * Return: 0 on success, -1 on failure.
 */
int display_help(char **command, __attribute__((unused)) int status)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(command[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');

	return (0);
}

/**
 * echo_bul - Execute Echo Built-in Command
 * @status: Status of the last command executed
 * @command: Parsed command
 *
 * Return: Always 0 (or execute normal echo).
 */
int echo_bul(char **command, int status)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(command[1], "$?", 2) == 0)
	{
		print_num_pch(status);
		PRINTER("\n");
	}
	else if (_strncmp(command[1], "$$", 2) == 0)
	{
		print_num(pid);
		PRINTER("\n");
	}
	else if (_strncmp(command[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_ech(command));

	return (1);
}
