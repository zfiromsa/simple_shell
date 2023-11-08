#include "main.h"

char **lists_cmd(char *cmd, char **cmds)
{
	char *token;
	int i;

	i = 0;
	token = strtok(cmds[i]," ");
	i++;
	while (token != NULL && i < MAX_CMD)
	{
		cmds[i] = malloc(strlen(token) + 1);
		strcpy(cmds[i], token);
		i++;
		token = strtok(NULL," ");
	}
	strcpy(cmds[i], NULL);
	return (cmds);
}

