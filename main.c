#include "main.h"

void main()
{
	_str_list *cmds;
	char *cmd;
	int i, status;
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
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
		}
		if (pid == 0)
		{
			exec_list(cmds);
			print_listint(cmds);
			sleep(3);
		}
		else
		{
			wait(&status);
		}
		free_list(&cmds);
	}
}

