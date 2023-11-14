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
		perror("Error exc 1");
	}
	if (pid == 0)
	{
		if (execve(list_cmds[0], list_cmds, env) == -1)
		{
			_free(list_cmds);
			perror("Error exc 2");
			return (0);
		}
	}
	else
	{
		wait(&status);
	}
	_free(list_cmds);
	return (1);
}

