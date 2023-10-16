#include "shell.h"

/**
 * count_number_token - returns the number of tokens in the line command
 * @lineptr: the line command
 * @delim: a string of delimiters
 * Return: the nbr of tokens
 */

int count_number_token(char *lineptr, const char *delim)
{
	int nbtokens = 0;
	char *token;

	token = strtok(lineptr, delim);
	while (token)
	{
		nbtokens++;
		token = strtok(NULL, delim);
	}
	return (nbtokens);
}

/**
 * splits_input - splits line command into arguments
 * @lineptr: the line command
 * @e: an array of environnement variables
 * @s: the previous status
 * Return: a pointer of pointers to arguments
 */
char **splits_input(char *lineptr, char **e, int s)
{
	char **av;
	char *token = NULL, *copy;
	int nbrTokens = 0, i = 0, j;
	const char *delim = " \t\n";

	copy = malloc(sizeof(char) * (_strlen(lineptr) + 1));
	if (copy == NULL)
		return (NULL);
	_strcpy(copy, lineptr);
	nbrTokens = count_number_token(copy, delim);
	av = malloc(sizeof(char *) * (nbrTokens + 1));
	if (!av)
		return (NULL);
	token = strtok(lineptr, delim);
	for (i = 0; token; i++)
	{
		av[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (av[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(av[j]);
			free(av);
			free(copy);
			return (NULL);
		}
		_strcpy(av[i], token);
		token = strtok(NULL, delim);
	}
	av[i] = NULL;
	replaceVar(av, e, s);
	free(copy);
	return (av);
}


/**
 * parse_line_command - parse line with ;
 * @lineptr: the giving string
 * Return: an array of pointers or NULL
 */
char **parse_line_command(char *lineptr)
{
	char *copyline, *token = NULL;
	int nbrTokens = 0, i = 0, j;
	const char *delim = ";";
	char **cmds;

	ignore_cmnt(lineptr);
	copyline = malloc(sizeof(char) * (_strlen(lineptr) + 1));
	if (!copyline)
		return (NULL);
	_strcpy(copyline, lineptr);
	nbrTokens = count_number_token(copyline, delim);
	cmds = malloc(sizeof(char *) * (nbrTokens + 1));
	if (!cmds)
		return (NULL);
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		cmds[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (cmds[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(cmds[j]);
			free(cmds);
			free(copyline);
			return (NULL);
		}
		_strcpy(cmds[i], token);
		token = strtok(NULL, delim);
	}
	cmds[i] = NULL;
	free(copyline);
	return (cmds);
}

