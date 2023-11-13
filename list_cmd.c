#include "main.h"

_str_list **lists_cmd(char *cmd, _str_list **cmds)
{
	char *token;
	int i, j, stlen;

	i = 0;
	j = 0;
	stlen = strlen(cmd);
	while (i < stlen)
	{
		if (cmd[i] == ' ')
		{
			j++;
			i++;
			if(cmd[j] != ' ')
			{
				j++;
				cmd[j] = cmd[i];
			}
		}
		j++;
		i++;
	}
	cmd[j] = '\0';
	i = 0;
	token = strtok(cmd," ");
	i++;
	add_nodeint_end(cmds, token);
	while (token != NULL)
	{
		token = strtok(NULL," ");
		add_nodeint_end(cmds, token);
	}
	return (cmds);
}

