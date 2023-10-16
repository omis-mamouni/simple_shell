#include "shell.h"

/**
 * add_new_element_end - add a new element at the end of the list
 * @head: a pointer to a pointers to environement vars
 * @name: name of  the element
 * @value: value of the element
 * Return: pointer to the new element
 */

Node_environment *add_new_element_end(Node_environment **head, char *name, char *value)
{
	Node_environment *new;
	Node_environment *current = *head;

	while (current && current->next != NULL)
		current = current->next;
	new = malloc(sizeof(Node_environment));
	if (!new)
		return (NULL);
	new->name = _strDuplicated(name);
	if (!new->name)
	{
		free_envNode_element(new);
		return (NULL);
	}
	if (value)
		new->value = _strDuplicated(value);
	else
		new->value = _strDuplicated("");
	if (!new->value)
	{
		free_envNode_element(new);
		return (NULL);
	}
	new->next = NULL;
	if (current)
		current->next = new;
	else
		*head = new;
	return (new);
}

/**
 * free_envNode_element - frees struct envNode element
 * @node: a pointer to the node
 */

void free_envNode_element(Node_environment *node)
{
	if (node->name)
		free(node->name);
	if (node->value)
		free(node->value);
	free(node);
}

/**
 * convert_environ_array_to_list - converts the environ array to list
 * @envp: a pointer to an array of pointer to environment vars
 * Return: the first element of the list
 */

Node_environment *convert_environ_array_to_list(char **envp)
{
	char *var, *name, *value;
	Node_environment *list = NULL;

	while (*envp)
	{
		var = _strDuplicated(*envp);
		if (!var)
		{
			perror("Error - Not enough space");
			return (NULL);
		}
		name = strtok(var, "=");
		value = strtok(NULL, "\0");
		add_new_element_end(&list, name, value);
		envp++;
		free(var);
	}
	return (list);
}

