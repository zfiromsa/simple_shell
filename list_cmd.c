#include "main.h"

/**
 * Func_list_cmds - split a given str of cmd to token
 * @cmds: string to be split to token
 * @list_cmds: a place of where we store splited token
 * Return: list_cmds or NULL
 */
char **Func_list_cmds(char *cmds, char **list_cmds)
{
	char *token, *tmp;
	int i;

	i = 0;
	if (strcmp(cmds, "exit"))
	{
		if (strncmp(cmds, "/bin/", 5) != 0)
		{
			tmp = malloc((strlen(cmds) + 6) * sizeof(char));
			if (tmp == NULL)
			{
				perror("Error malloc");
				return (NULL);
			}
			strcpy(tmp, "/bin/");
			strcat(tmp, cmds);
			cmds = tmp;
		}
	}
	list_cmds = malloc(sizeof(char *) * 2);
	if (list_cmds == NULL)
	{
		perror("Error malloc ");
		return (NULL);
	}
	token = strtok(cmds, " \n");
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
			return (NULL);
		}
		i++;
		list_cmds = realloc(list_cmds, ((i + 1) * sizeof(char *)));
		if (list_cmds == NULL)
		{
			perror("Error realloc");
			return (NULL);
		}
		token = strtok(NULL, " \n");
	}
	list_cmds[i] = NULL;
	return (list_cmds);
}

