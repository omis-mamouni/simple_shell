#include "shell.h"


/**
 * GetBuild_f - get build in function
 * @c: the giving command
 * Return: the associated function
 */

int (*GetBuild_f(char *c))(char *x, int n, char **a, char **e, int s, int l)
{
	buildin_commands b_in[] = {
		{"exit", exit_ee},
		{"env", env_rm},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (i < 2)
	{
		if (!_strcmp(b_in[i].cmd, c))
			return (b_in[i].func);
		i++;
	}
	return (NULL);
}

