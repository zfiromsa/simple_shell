#include "main.h"

void lists_cmd(char *cmd, _str_list **cmds)
{
	char *token;
	int i;

	i = 0;
	token = strtok(cmd," ");
	i++;
	add_nodeint_end(cmds, token);
	while (token != NULL)
	{
		token = strtok(NULL," ");
		add_nodeint_end(cmds, token);
	}
	exit(0);
}

