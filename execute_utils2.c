#include "main.h"

/**
 * exit_sh - Exits the shell
 * @datashell: Data structure containing relevant data
 *             (status and args)
 *
 * Return: 0 on success.
 */
int exit_sh(datashell *datashell)
{
	unsigned int ustat;
	int is_dgt, strlen, big_n;

	if (datashell->args[1] != NULL)
	{
		ustat = _atoi(datashell->args[1]);
		is_dgt = _isdigit(datashell->args[1]);
		strlen = _strlen(datashell->args[1]);
		big_n = ustat > (unsigned int)INT_MAX;
		if (!is_dgt || strlen > 10 || big_n)
		{
			get_err(datashell, 2);
			datashell->status = 2;
			return (1);
		}
		datashell->status = (ustat % 256);
	}
	return (0);
}

/**
 * execute_line - Finds built-ins and commands.
 * @datash: Data relevant (args).
 *
 * Return: 1 on success.
 */
int execute_line(datashell *datash)
{
	int (*builtin)(datashell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_bltn(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (command_exec(datash));
}

/**
 * err_environ - generates an error message for env-related operations.
 * @data_sh: data relevant to the shell (counter, arguments).
 *
 * Return: Error message string.
 */
char *err_environ(datashell *data_sh)
{
	int length;
	char *err, *txt, *vstr;

	vstr = conv_itoa(data_sh->counter);
	txt = ": Unable to add/remove from environment\n";
	length = _strlen(data_sh->av[0]) + _strlen(vstr);
	length += _strlen(data_sh->args[0]) + _strlen(txt) + 4;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}

	_strcpy(err, data_sh->av[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, txt);
	_strcat(err, "\0");
	free(vstr);

	return (err);
}

/**
 * err_path126 - generates an error message for path-related
 *               operations with permission denied.
 * @data_sh: data relevant to the shell (counter, arguments).
 *
 * Return: The error message string.
 */
char *err_path126(datashell *data_sh)
{
	int length;
	char *vstr, *err;

	vstr = conv_itoa(data_sh->counter);
	length = _strlen(data_sh->av[0]) + _strlen(vstr);
	length += _strlen(data_sh->args[0]) + 24;
	err = malloc(sizeof(char) * (length + 1));
	if (err == 0)
	{
		free(err);
		free(vstr);
		return (NULL);
	}
	_strcpy(err, data_sh->av[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(vstr);
	return (err);
}

/**
 * conc_err_msg - concatenates an error message for the 'cd' command.
 * @data_sh: data relevant to the shell (directory, arguments).
 * @disp_msg: message to be displayed.
 * @err: output message buffer.
 * @vstr: counter lines.
 *
 * Return: The concatenated error message.
 */
char *conc_err_msg(datashell *data_sh, char *disp_msg, char *err, char *vstr)
{
	char *illegal_flag;

	_strcpy(err, data_sh->av[0]);
	_strcat(err, ": ");
	_strcat(err, vstr);
	_strcat(err, ": ");
	_strcat(err, data_sh->args[0]);
	_strcat(err, disp_msg);
	if (data_sh->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data_sh->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(err, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(err, data_sh->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}