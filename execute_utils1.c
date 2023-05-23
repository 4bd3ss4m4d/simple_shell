#include "simple_shell.h"

/**
 * check_cmd - Execute Simple Shell Command (Fork, Wait, Execute)
 * @cmd: Parsed command
 * @input: User input
 * @c: Shell execution time case of command not found
 * @argv: Program name
 *
 * Return: 1 if command is NULL, -1 on wrong command,
 *         0 on command executed.
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			command_path(cmd);

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_err(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}

/**
 * handle_builtin - Handle Built-in Commands
 * @cmd: Parsed command.
 * @er: Status of the last execution.
 *
 * Return: -1 on failure, 0 on success (return value of
 *         executed built-in command).
 */
int handle_builtin(char **cmd, int er)
{
	builtin_t bil[] = {
	    {"cd", change_dir},
	    {"env", dis_env},
	    {"help", display_help},
	    {"echo", echo_bul},
	    {"history", disp_hist},
	    {NULL, NULL}};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->func(cmd, er));
		}
		i++;
	}
	return (-1);
}


/**
 * signal_to_handel - Handle SIGINT (^C)
 * @sig: Captured signal
 *
 * Return: Void.
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
		PRINTER("\n$ ");
}
