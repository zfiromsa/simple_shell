#include "main.h"

void main()
{
	char *cmds[MAX_CMD];
	char *cmd;
	int i;
	ssize_t len, rd;

	i = 0;
	len = 0;
	cmd = NULL;
	while (true)
	{
		printf("enter your cmd: $ ");
		rd = getline(&cmd, &len, stdin);
		if (rd == -1 || strcmp(cmd, "ex") == 0)
		{
			free(cmd);
			break;
		}
		lists_cmd(cmd, cmds);
		while (cmds[i])
		{
			printf("cmd %d:  %s", i+1, cmds[i]);
			free(cmds[i]);
			i++;
		}
		free(cmd);
		cmd = NULL;
	}
}

