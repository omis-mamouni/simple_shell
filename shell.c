#include "shell.h"

/**
 * main - entry points to the simple version of the shell
 * @argc: nbr of arguments
 * @argv: an array of pointers of arguments
 * Return:0 success
 */


int main(__attribute__((unused)) int argc, char **argv)
{
	ssize_t nbchar = 0;
	size_t n = 0;
	char *lineptr = NULL;
	char **e = environ, **av = NULL, **cmd = NULL;
	int len = 0, status = 0, i, lvl = 0, flag = 0;
	int (*p_func)(char *exe, int ac, char **as, char **e, int st, int l);

	signal(SIGINT, SIGINT_is_sent);
	while (1)
	{
		printPromptString();
		nbchar = getline(&lineptr, &n, stdin);
		if (nbchar <= 0)
		{
			free(lineptr);
			exit(status);
		}
		flag = 1, cmd = parse_line_command(lineptr);
		for (i = 0; cmd[i]; i++)
		{
			av = splits_input(cmd[i], e, status);
			len = arrayLength(av);
			if (len > 0)
			{
				p_func = get_build_function(av[0]);
				if (p_func != NULL)
				{
					lvl++;
					status = p_func(argv[0], len, av, e, status, lvl);
					if (status != 0)
						exe_exit_cmd(status, av, lineptr, cmd);
				}
				else
					status = execute_cmd(argv[0], av, e, &flag, &lvl);
			}
			free_array(av);
		}
		free_array(cmd);
	}
	return (0);
}


