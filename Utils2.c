#include "shell.h"

/**
 * convertInteger - converts an integer to a specific base
 * @n: the giving integer
 * @base: the base to be converted to
 * @upper_o_n: indicates if output upper od lower case
 * Return: the conversion string
 */

char *convertInteger(int n, int base, int upper_o_n)
{
	static char *base_digits;
	static char buffer[50];
	char *p_convert;

	base_digits = upper_o_n ? "0123456789ABCDEF" :
			"0123456789abcdef";

	p_convert = &buffer[49];
	*p_convert = '\0';

	do {
		*--p_convert = base_digits[n % base];
		n /= base;
	} while (n != 0);
	return (p_convert);
}

/**
 * replaceVar - handle variables
 * @args: an array of pointers to arguments
 * @e: an array of environment variables
 * @s: the previous status
 * Return: 0 Success
 */

int replaceVar(char **args, char **e, int s)
{
	int i;
	char *value;

	for (i = 0; args[i] != NULL; i++)
	{
		if (args[i][0] == '$' && args[i][1] == '\0')
			continue;
		else if (_strcmp(args[i], "$?") == 0)
		{
			free(args[i]);
			args[i] = _strDuplicated(convertInteger(s, 10, 0));
			continue;
		}
		else if (_strcmp(args[i], "$$") == 0)
		{
			free(args[i]);
			args[i] = _strDuplicated(convertInteger(getpid(), 10, 0));
			continue;
		}
		else if (args[i][0] == '$')
		{
			value = _get_environment_variable(&args[i][1], e);
			free(args[i]);
			if (value)
			{
				args[i] = _strDuplicated(value);
				free(value);
				continue;
			}
			args[i] = _strDuplicated("");
		}
	}
	return (0);
}

