#include "main.h"

void main()
{
	_str_list *cmds;
	char *cmd;
	int i;
	pid_t pid;
	ssize_t rd;
	size_t len;

	i = 0;
	len = 0;
	cmd = NULL;
	cmds = NULL;
	while (true)
	{
		printf("enter your cmd: $ ");
		rd = getline(&cmd, &len, stdin);
		if (rd == -1 || strcmp(cmd, "ex") == 0)
		{
			free(cmd);
			break;
		}
		lists_cmd(cmd, &cmds);
		print_listint(cmds);
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
		}
		exec_list(cmds);

		free_list(&cmds);
	}
}

