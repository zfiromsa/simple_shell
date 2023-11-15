#include "main.h"

/**
 * execute - execute using given parm by creating new processer
 *
 * @list_cmds: the address of each cmd termineted by NULL
 * @env: enviroment parm
 * Return: 0 or 1
 */
int execute(char **list_cmds, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error pid");
		return (1);
	}
	else if (pid == 0)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
		if (execve(list_cmds[0], list_cmds, env) == -1)
		{
			perror("Error exc");
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

