#include "simple_shell.h"

/**
 * command_path - Search for an executable command in the $PATH
 * @command: Parsed input command
 *
 * Return: 0 on success, 1 on failure
 */
int command_path(char **command)
{
	char *path, *value, *comd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		comd_path = build(*command, value);
		if (stat(comd_path, &buf) == 0)
		{
			*command = _strdup(comd_path);
			free(comd_path);
			free(path);
			return (0);
		}
		free(comd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * build - Build the full path of a command
 * @token: Executable command
 * @val: Directory containing the command
 *
 * Return: Parsed full path of the command or NULL in case of failure
 */
char *build(char *token, char *val)
{
	char *command;
	size_t len;

	len = _strlen(val) + _strlen(token) + 2;
	command = malloc(sizeof(char) * len);
	if (command == NULL)
	{
		return (NULL);
	}

	memset(command, 0, len);

	command = _strcat(command, val);
	command = _strcat(command, "/");
	command = _strcat(command, token);

	return (command);
}

/**
 * _getenv - Gets the value of an environment variable by name
 * @env_name: Name of the environment variable
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *env_name)
{
	size_t nl, vl;
	char *value;
	int i, k, j;

	nl = _strlen(env_name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(env_name, environ[i], nl) == 0)
		{
			vl = _strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = nl + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}

