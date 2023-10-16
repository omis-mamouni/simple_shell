#include "shell.h"

/**
 * exit_ee - exit the current process
 * @exe: executable name
 * @ac: number of arguments
 * @as: a pointer of pointers to arguments
 * @e: a pointer of environment variables
 * @s: the status of the previous command
 * @l: line number
 * Return: 0 success
 */


int exit_ee(char *exe, int ac, char **as, char **e, int s, int l)
{
	int status = 200, i;
	char *error;
	char *level = convertInteger(l, 10, 0);

	(void)e;
	if (ac > 2)
	{
		print_error_message(exe, "Usage: exit status");
		return (1);
	}
	if (as[1] != NULL)
	{
		for (i = 0; as[1][i] != '\0'; i++)
		{
			if (!_checkDigit(as[1][i]))
			{
				error = malloc(sizeof(char) * (_strlen(as[1]) +
						       _strlen(level) + 27));
				_strcpy(error, level);
				_strcat(error, ": exit: ");
				_strcat(error, "Illegal number: ");
				_strcat(error, as[1]);
				print_error_message(exe, error);
				free(error);
				return (2);
			}
		}
		status = _string_to_integer(as[1]);
	}
	else if (s != 0)
		status = s;
	return (status);
}


/**
 * env_rm - print environment variables
 * @exe: executable name
 * @ac: number of arguments
 * @as: a pointer of pointers to arguments
 * @e: a pointer of environment variables
 * @s: the status of the previous command
 * @l: line number
 * Return: 0 success
 */

int env_rm(char *exe, int ac, char **as, char **e, int s, int l)
{
	char **envp = e;

	(void)as;
	(void)s;
	(void)l;
	if (ac > 1)
	{
		print_error_message(exe, "Usage : env");
		return (1);
	}
	while (*envp)
	{
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}
	return (0);
}

