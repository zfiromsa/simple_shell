#include "main.h"

/**
 * execute - execute using given parm by creating new processer
 *
 * @list_cmds: the address of each cmd termineted by NULL*
 *
 * Return: 0 or 1
 */
int execute(char **list_cmds)
{
	pid_t pid;
	int status;

	if (!strcmp(list_cmds[0], "exit"))
	{
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error ");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(list_cmds[0], list_cmds, environ) == -1)
		{
			perror("Error ");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}

