#include "main.h"

/**
 * execute - execute using given parm by creating new processer
 *
 * @list_cmds: the address of each cmd termineted by NULL
 * @env: enviroment parm
 * Return: 0 or 1
 */
int execute(char **list_cmds)
{
	pid_t pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	pid = fork();
	(void)list_cmds;
	if (pid == -1)
	{
		perror("Error pid");
		return (1);
	}
	else if (pid == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("Error exc");
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}

