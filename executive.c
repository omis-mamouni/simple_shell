#include "shell.h"

/**
 * SIGINT_is_sent - prints a new line when a signal SIGINT is sent
 * @signal: the sent signal
 */

void SIGINT_is_sent(int signal)
{
	if (signal == SIGINT)
		write(STDIN_FILENO, "\n$ ", 3);
}

/**
 * execute_cmd - executes the giving command
 * @exe: executable name
 * @av: an array of arguments
 * @e: an array of environement variables
 * @f: line flag
 * @l: line counter
 * Return: status code
 */

int execute_cmd(char *exe, char **av, char **e, int *f, int *l)
{
	pid_t child;
	int st;
	char *path, *cmd = NULL;
	struct stat s;

	if (av)
	{
		if (*f == 1)
			(*l)++, *f = 0;
		path = _get_environment_variable("PATH", e);
		if (path != NULL || stat(av[0], &s) == 0)
			cmd = _locateWhich(av[0], path);
		if (cmd)
		{
			child = fork();
			if (child == -1)
			{
				print_error_message(exe, "Fork fails");
				return (1);
			}
			else if (child == 0)
			{
				if (execve(cmd, av, e) == -1)
				{
					perror(exe);
					exit(errno);
				}
			}
			wait(&st);
			free(path);
			free(cmd);
			return (WEXITSTATUS(st));
		}
		free(path);
		free(cmd);
		return (print_command_notFound_error(exe, av, *l));
	}
	return (0);
}

/**
 * print_error_message - print error message
 * @exe: executable name
 * @desc: error message
 */

void print_error_message(char *exe, char *desc)
{
	char *error;

	error = malloc(sizeof(char) * (_strlen(exe) + _strlen(desc) + 5));
	if (error == NULL)
	{
		write(STDERR_FILENO, "Not enough space", 16);
		return;
	}
	_strcpy(error, exe);
	_strcat(error, ": ");
	_strcat(error, desc);
	_strcat(error, "\n\0");
	write(STDERR_FILENO, error, _strlen(error));
	free(error);
}


/**
 * print_command_notFound_error - prints command not found error
 * @exe: executable name
 * @av: an array of pointers to arguments
 * @l: line counter
 * Return: 127
 */

int print_command_notFound_error(char *exe, char **av, int l)
{
	char *error;
	char *level = convertInteger(l, 10, 0);

	error = malloc(sizeof(char) * (_strlen(exe) + _strlen(av[0])
				+ _strlen(level) + 26));
	if (error == NULL)
	{
		write(STDERR_FILENO, "Not enough space", 16);
		return (1);
	}
	_strcpy(error, exe);
	_strcat(error, ": ");
	_strcat(error, level);
	_strcat(error, ": ");
	_strcat(error, av[0]);
	_strcat(error, ": not found");
	_strcat(error, "\n\0");
	write(STDERR_FILENO, error, _strlen(error));
	free(error);
	return (127);
}

