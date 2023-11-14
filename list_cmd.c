#include "main.h"

/**
 * Func_list_cmds - split a given str of cmd to token
 *
 * @cmds: string to be split to token
 * @list_cmds: a place of where we store splited token
 * Return: list_cmds or NULL
 */
char **Func_list_cmds(char *cmds, char **list_cmds)
{
	int i;
	char *token;

	i = 0;
	list_cmds = malloc(sizeof(char *));
	if (list_cmds == NULL)
	{
		perror("Error Fun 1");
		return (NULL);
	}
	token = strtok(cmds, " ");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		list_cmds[i] = token;
		token = strtok(NULL, " ");
		i++;
		list_cmds = realloc(list_cmds, ((i + 1) * sizeof(char *)));
		if (list_cmds == NULL)
		{
			perror("Error Fun 2");
			break;
		}
	}
	list_cmds[i] = NULL;
	return (list_cmds);
}

