#include "simple_shell.h"

/**
 * parse_command - Parse Line Of Input
 * @inp: User Input To Parse
 *
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_command(char *inp)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (inp == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(inp, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * create_env_array - Creat Array of Enviroment Variable
 * @env_arr: Array of Enviroment Variable
 * Return: Void
 */
void create_env_array(char **env_arr)
{
	int i;

	for (i = 0; environ[i]; i++)
		env_arr[i] = _strdup(environ[i]);
	env_arr[i] = NULL;
}

/**
 * check_bltn - check builtin
 *
 * @command:command to check
 * Return: 0 Succes -1 Fail
 */
int check_bltn(char **command)
{
	builtin_t func[] = {
	    {"cd", NULL},
	    {"help", NULL},
	    {"echo", NULL},
	    {"history", NULL},
	    {NULL, NULL}};
	int i = 0;

	if (*command == NULL)
	{
		return (-1);
	}

	while ((func + i)->command)
	{
		if (_strcmp(command[0], (func + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
