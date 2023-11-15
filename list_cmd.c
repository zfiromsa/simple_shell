#include "main.h"

/**
 * Func_list_cmds - split a given str of cmd to token
 * @cmds: string to be split to token
 * @list_cmds: a place of where we store splited token
 * Return: list_cmds or NULL
 */
char **Func_list_cmds(char *cmds, char **list_cmds)
{
	char *token;
	int i, len_cmd;

	i = 0;
	len_cmd = 15;
	list_cmds = malloc(((len_cmd + 1) * sizeof(char *)));
	if (list_cmds == NULL)
	{
		perror("Error malloc ");
		return (NULL);
	}
	token = strtok(cmds, " ");
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		list_cmds[i] = strdup(token);
		if (list_cmds[i] == NULL)
		{
			perror("Error strdup ");
			return (list_cmds);
		}
		i++;
		if (i >= len_cmd)
		{
			len_cmd *= 2;
			list_cmds = realloc(list_cmds, ((len_cmd + 1) * sizeof(char *)));
			if (list_cmds == NULL)
			{
				perror("Error realloc");
				return (list_cmds);
			}
		}
		token = strtok(NULL, " ");
	}
	list_cmds[i] = NULL;
	return (list_cmds);
}

