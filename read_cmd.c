#include "main.h"

/**
 * read_cmd - it read from stdin store to a gaven parmet
 *
 * @cmds: pointer hold the address of string
 * Return: address of string
 */
char *read_cmd(char *cmds)
{
	size_t len;

	len = 0;
	getline(&cmds, &len, stdin);
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
	return (cmds);
}

