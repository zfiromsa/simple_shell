#include "main.h"

void main()
{
	char *cmds[MAX_CMD];
	char *cmd;
	int i;

	i = 0;
	while (true)
	{
		cmd = readline("enter your cmd: $ ");
		if (strcmp(cmd, "ex") == 0)
		{
			free(cmds);
			break;
		}
		lists_cmd(cmd, cmds);
		while (cmds[i])
		{
			printf("cmd %d:  %s", i+1, cmds[i]);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}

