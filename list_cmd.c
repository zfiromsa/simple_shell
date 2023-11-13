#include "main.h"

_str_list **lists_cmd(char *cmd, _str_list **cmds)
{
	char *token;
	int i;

	i = 0;
	token = strtok(cmd," ");
	i++;
	add_nodeint_end(cmds, token);
	if (strcmp(token, "exit") == 0)
	{
		exit(0);
	}
	while (token != NULL)
	{
		token = strtok(NULL," ");
		add_nodeint_end(cmds, token);
	}
	return (cmds);
}

