#include "main.h"

int main(int argc, char *argv[], char **envp)
{
	_str_list *cmds;
	char *cmd;
	int status;
	pid_t pid;
	ssize_t rd;
	size_t len;

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
			exec_list(cmds, envp);
			print_listint(cmds);
			sleep(3);
		}
		else
		{
			wait(&status);
		}
		free_list(&cmds);
	}
	return (0);
}

