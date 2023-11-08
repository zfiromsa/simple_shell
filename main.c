#include "main.h"

void main()
{
	char *cmds[max_cmd], *cmd;
	int i;

	i = 0;
	while (true)
	{
		cmd = readline("enter your cmd: $ ");
		if (strcmp(cmd, "ex") == 0)
		{
			free(cmd);
			break;
		}
		lists_cmd(&cmd, &cmds);
		while (cmds[i])
		{
			printf("cmd %d:  %s", i+1, cmds[i]);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}

